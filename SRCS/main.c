/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/04 21:48:00 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

void	first_cmd(t_pipex *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1 && ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		ft_printf("- INFILE provided is incorrect or doesn't exist ! -\n");
		clean_exit(data, EXIT_FAILURE);	
	}
	dup2(data->infile, STDIN_FILENO);
	close(data->infile);
}

void	last_cmd(t_pipex *data, int argc, char **argv)
{
	data->outfile = open(argv[argc - 1], O_WRONLY ,O_CREAT, O_TRUNC, 0755);
	if (data->outfile == -1)
	{
		// ft_printf("- Error(s) occured when trying to create or modify OUTFILE\n");
		perror("open ");
		clean_exit(data, EXIT_FAILURE);
	}
	dup2(data->outfile, STDOUT_FILENO);
	close(data->outfile);
}

void	parent(t_pipex *data)
{
	fprintf(stderr, "fd[0]:%i fd[1]:%i prev:%i\n", data->fd[0],data->fd[1],data->old_read_fd);
	close(data->fd[1]);
	if (data->executed_cmd)
		close(data->old_read_fd);
	data->old_read_fd = data->fd[0];
	if (data->executed_cmd == data->cmd_count)
		close(data->fd[0]);
}

void	while_cmd(t_pipex *data, int argc, char **argv, char **envp)
{
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
		if (data->executed_cmd == 0)
			first_cmd(data, argv);
		if (data->executed_cmd == data->cmd_count - 1)
			last_cmd(data, argc, argv);
		go_exec(data, envp);
	}
	else
		parent(data);
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
	while (data.executed_cmd != data.cmd_count)
	{
		while_cmd(&data, argc, argv, envp);
		data.executed_cmd++;
	}
	wait_child(&data);
	clean_exit(&data, EXIT_SUCCESS);
}
