/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/04 21:26:32 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

void	while_cmd(t_pipex *data, char **envp)
{
	data->old_read_fd = -1;
	while (data->executed_cmd != (data->cmd_count))
	{
		// fprintf(stderr, "hello\n");
		if (pipe(data->fd) == -1)
			clean_exit(data, PIPE_ERROR);
		data->child_pid = fork();
		if (data->child_pid == -1)
			clean_exit(data, FORK_ERROR);
		if (!data->child_pid)
		{
			if (data->executed_cmd != 0)
			{
				dup2(data->old_read_fd, STDIN_FILENO);
				close(data->old_read_fd);
			}
			if (data->executed_cmd != (data->cmd_count) - 1)
				dup2(data->fd[1], STDOUT_FILENO);
			close(data->fd[0]);
			close(data->fd[1]);
			
			// int fd;
			// if (data->executed_cmd == 0)
			// {
			// 	fd = open(infile, O_RDONLY);
			// 	if (fd == -1)
			// 		clean_exit(data, FORK_ERROR);
			// 	dup2(fd, STDIN_FILENO)
			// 	close(fd);
			// }
			// if (data->executed_cmd == data->cmd_count - 1)
			// {
			// 	fd = open(outfile, O_TRUNC | O_WRONLY | O_CREAT);
			// 	if (fd == -1)
			// 		clean_exit(data, FORK_ERROR);
			// 	dup2(fd, STDOUT_FILENO)
			// 	close(fd);
			// }
			go_exec(data, envp);
			exit(127);
		}
		else
		{
			fprintf(stderr, "fd[0]:%i fd[1]:%i prev:%i\n", data->fd[0],data->fd[1],data->old_read_fd);
			close(data->fd[1]);
			if (data->executed_cmd)
				close(data->old_read_fd);
			data->old_read_fd = data->fd[0];
		}
		data->executed_cmd++;
	}
	close(data->fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	
	if (argc < 5)
	{
		ft_printf("- Too few arguments... -\n");
		clean_exit(&data, EXIT_FAILURE);
	}
	init_struct(&data, argc);
	fill_struct(&data, argc, argv);
	// first_cmd(&data, argv, envp);
	while_cmd(&data, envp);
	// last_cmd(&data, argv, argc, envp);
	wait_child(&data);
	clean_exit(&data, EXIT_SUCCESS);
}
