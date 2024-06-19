/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/19 17:44:42 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

void	first_cmd(t_pipex *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
	{
		ft_printf(2, "\033[1;5;31m- INFILE provided is incorrect ");
		ft_printf(2, "or doesn't exist ! -\n\033[0m");
		clean_exit(data, EXIT_FAILURE);
	}
	dup2(data->infile, STDIN_FILENO);
	close(data->infile);
}

void	last_cmd(t_pipex *data, int argc, char **argv)
{
	int	flags;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (data->is_heredoc == 1)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	data->outfile = open(argv[argc - 1], flags, 0755);
	if (data->outfile == -1)
	{
		ft_printf(2, "\033[1;5;31m- Error(s) occured when trying ");
		ft_printf(2, "to create or modify OUTFILE -\n\033[0m");
		clean_exit(data, EXIT_FAILURE);
	}
	dup2(data->outfile, STDOUT_FILENO);
	close(data->outfile);
}

void	parent(t_pipex *data)
{
	close(data->fd[1]);
	if (data->executed_cmd)
		close(data->old_read_fd);
	data->old_read_fd = data->fd[0];
	if (data->executed_cmd == data->cmd_count - 1)
		close(data->fd[0]);
	data->executed_cmd++;
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
		ft_printf(1, "\033[1;5;31m- Too few arguments... -\n\033[0m");
		exit(EXIT_FAILURE);
	}
	init_struct(&data, argc);
	fill_struct(&data, argc, argv);
	if (ft_strcmp("here_doc", argv[1]) == 0)
	{
		if (argc < 6)
		{
			ft_printf(1, "\033[1;5;31m- Too few arguments... -\n\033[0m");
			clean_exit(&data, EXIT_FAILURE);
		}
		data.is_heredoc = 1;
		data.limiter = ft_strdup(argv[2]);
		handle_heredoc(&data);
	}
	while (data.executed_cmd != data.cmd_count)
		while_cmd(&data, argc, argv, envp);
	wait_child(&data);
	unlink("./here_doc");
	clean_exit(&data, EXIT_SUCCESS);
}
