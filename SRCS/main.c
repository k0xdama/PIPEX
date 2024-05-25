/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/25 22:20:52 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

char *search_bin(t_pipex *data, char **envp)
{
	char **tab_path;
	char *path_to_try;
	char *tmp;
	
	tab_path = NULL;
	tab_path = ft_split(data->all_path, ':');
	while (*tab_path)
	{
		path_to_try = NULL;
		tmp = NULL;
		tmp = ft_strjoin(*tab_path, "/");
		path_to_try = ft_strjoin(tmp, *(data->cmds));
		if (access(path_to_try, X_OK) == -1)
			tab_path++;
		else
			return (path_to_try);
	}
	return (NULL);
}

void	go_exec(t_pipex *data, char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) != 0)
			envp++;
		else
		{
			data->all_path = *envp;
			envp++;
		}
	}
	data->path_bin = search_bin(data, envp);
	if (!data->path_bin)
		clean_exit(ACCESS_ERROR);
	else
		execve();
}

void	last_cmd(t_pipex *data, char **envp)
{
	data->child_pid = fork();
	if (data->child_pid == -1)
		clean_exit(FORK_ERROR);
	if (!data->child_pid)
	{
		close(data->fd[1]);
		dup2(data->outfile, STDOUT_FILENO);
		go_exec(data, envp);
	}
	else
	{
		close(data->fd[0]);
		close(data->infile);
		close(data->outfile);
	}
}

void	while_cmd(t_pipex *data, char **envp)
{
	while(data->executed_cmd != (data->cmd_count - 1))
	{
		if (pipe(data->fd) == -1)
			clean_exit(PIPE_ERROR);
		data->child_pid = fork();
		if (data->child_pid == -1)
			clean_exit(FORK_ERROR);
		if (!data->child_pid)
		{
			close(data->fd[0]);
			if (data->executed_cmd == 0)
				dup2(data->infile, STDIN_FILENO);
			dup2(data->fd[1], STDOUT_FILENO);
			go_exec(data, envp);
		}
		else
		{
			close(data->fd[1]);
			dup2(data->fd[0], STDIN_FILENO);
			data->executed_cmd++;
		}
	}
	last_cmd(data, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	
	if (argc < 5)
	{
		ft_printf("- Too few arguments... -\n");
		exit(EXIT_FAILURE);
	}
	init_struct(&data, argc);
	data.infile = open(argv[1], O_RDONLY);
	if (data.infile == -1 && ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		ft_printf("- INFILE provided is incorrect or doesn't exist ! -\n");
		exit(EXIT_FAILURE);	
	}
	data.outfile = open(argv[argc - 1], O_CREAT, O_TRUNC, O_WRONLY, 0777);
	if (data.outfile == -1)
	{
		ft_printf("- Error(s) occured when trying to create or modify OUTFILE\n");
		exit(EXIT_FAILURE);
	}
	fill_struct(&data, argc, argv, envp);
	while_cmd(&data, envp);
}
