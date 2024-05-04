/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/04 07:48:03 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

void	free_all(t_pipex *data)
{
	int i;
	
	i = 0;
	if (data->cmds)
	{
		while (data->cmds[i++])
			free(data->cmds[i]);
		free(data->cmds);
	}
	i = 0;
	if (data->pipe_tab)
	{
		while (data->pipe_tab[i++])
			free(data->cmds[i]);
		free(data->pipe_tab);
	}
}

void	init_struct(t_pipex *data, int argc)
{
	int	i;

	i = 0;
	data->cmd_count = argc - 3;
	data->pipe_count = data->cmd_count - 1;
	data->infile = NULL;
	data->outfile = NULL;
	data->cmds = malloc(data->cmd_count * sizeof(char *));
	if (!data->cmds)
		exit(EXIT_FAILURE);
	data->is_heredoc = 0;
	data->pipe_tab = malloc(data->pipe_count * sizeof(int *));
	if (data->pipe_tab == NULL)
		exit(EXIT_FAILURE);
	while(data->pipe_tab[i++])
	{
		data->pipe_tab[i] = malloc(2 * sizeof(int));
		if (!data->pipe_tab[i])
		{
			free_all(data);
			exit(EXIT_FAILURE);
		}
	}
}

void check_args(char **argv)
{
	
}

void	fill_struct(t_pipex *data, int argc, char **argv)
{
	int arg_i;
	int	cmd_i;

	arg_i = 2;
	cmd_i = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
		data->is_heredoc = 1;
	else
		data->infile = argv[1];
	data->outfile = argv[argc - 1];
	while (arg_i != (argc - 1))
	{
		data->cmds[cmd_i] = ft_strdup(argv[arg_i]);
		arg_i++;
	}
	check_args()?	
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int pid;
	int	ret;
	
	if (argc <= 3)
		exit(EXIT_FAILURE);
	infile = argv[1];
	cmd_arg = ft_split(argv[2], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		ret = execve(cmd, cmd_arg, envp);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

//argv[2] = "ping google.fr"

//cmd = "ping"
//google.fr