/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/03 22:04:52 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

// void	first_cmd(t_pipex *data, char **argv, char **envp)
// {
// 	if (pipe(data->fd) == -1)
// 		clean_exit(data, PIPE_ERROR);
// 	data->child_pid = fork();
// 	if (data->child_pid == -1)
// 		clean_exit(data, FORK_ERROR);
// 	if (!data->child_pid)
// 	{
// 		data->infile = open(argv[1], O_RDONLY);
// 		if (data->infile == -1 && ft_strncmp(argv[1], "here_doc", 8) != 0)
// 		{
// 			ft_printf("- INFILE provided is incorrect or doesn't exist ! -\n");
// 			clean_exit(data, EXIT_FAILURE);	
// 		}
// 		close(data->fd[0]);
// 		dup2(data->infile, STDIN_FILENO);
// 		close(data->infile);
// 		dup2(data->fd[1], STDOUT_FILENO);
// 		close(data->fd[1]);
// 		go_exec(data, envp);
// 	}
// 	else
// 		dup2(data->fd[0], STDIN_FILENO);
// }

// void	last_cmd(t_pipex *data, char **argv, int argc, char **envp)
// {
// 	data->child_pid = fork();
// 	if (data->child_pid == -1)
// 		clean_exit(data, FORK_ERROR);
// 	if (!data->child_pid)
// 	{
// 		close(data->fd[0]);
// 		close(data->fd[1]);
// 		data->outfile = open(argv[argc - 1], O_CREAT, O_TRUNC, O_WRONLY, 0777);
// 		if (data->outfile == -1)
// 		{
// 			ft_printf("- Error(s) occured when trying to create or modify OUTFILE\n");
// 			clean_exit(data, EXIT_FAILURE);
// 		}
// 		dup2(data->outfile, STDOUT_FILENO);
// 		close(data->outfile);
// 		go_exec(data, envp);
// 	}
// 	else
// 	{
// 		close(data->fd[0]);
// 		close(data->fd[1]);
// 	}
// }
/* 
enfant
	premier truc que tu fais
		if (data->executed_cmd != 0)
			// dup prev en STDIN
			// close prev
		if (data->executed_cmd != data->cmd_count - 1)
			// dup fd[1] en STDOUT
		close(fd[0])
		close(fd[1])

parent
	close fd[1]
	if (data->executed_cmd > 0)
		close(prev)
	prev = fd[0]

fin du programme boucle etc
	close(fd[0])
*/

// ./pipex	Makefile	ls	echo	grep	cat	/dev/stdout
// 					0	1		2		3

// if pas la premiere
// 	1 2 3
// if pas la derniere
// 	0 1 2

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
			
			int fd;
			if (data->executed_cmd == 0)
			{
				fd = open(infile, O_RDONLY);
				if (fd == -1)
					clean_exit(data, FORK_ERROR);
				dup2(fd, STDIN_FILENO)
				close(fd);
			}
			if (data->executed_cmd == data->cmd_count - 1)
			{
				fd = open(outfile, O_TRUNC | O_WRONLY | O_CREAT);
				if (fd == -1)
					clean_exit(data, FORK_ERROR);
				dup2(fd, STDOUT_FILENO)
				close(fd);
			}
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


// void	while_cmd(t_pipex *data, char **envp)
// {
// 	while(data->executed_cmd != (data->cmd_count - 1))
// 	{
// 		data->old_read_fd = data->fd[0];	
// 		if (pipe(data->fd) == -1)
// 			clean_exit(data, PIPE_ERROR);
// 		data->child_pid = fork();
// 		if (data->child_pid == -1)
// 			clean_exit(data, FORK_ERROR);
// 		if (!data->child_pid)
// 		{
// 			dup2(data->old_read_fd, STDIN_FILENO);
// 			close(data->old_read_fd);
// 			close(data->fd[0]);
// 			dup2(data->fd[1], STDOUT_FILENO);
// 			close(data->fd[1]);
// 			go_exec(data, envp);
// 		}
// 		dup2(data->fd[0], STDIN_FILENO);
// 		data->executed_cmd++;
// 	}
// }

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
