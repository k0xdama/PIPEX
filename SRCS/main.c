/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/16 18:32:12 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

void	free_all(t_pipex *data, int merror)
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
	if (merror == 1)
		ft_printf("- MALLOC ERROR ! -\n");
}

void	init_struct(t_pipex *data, int argc)
{
	int	i;

	i = 0;
	data->cmd_count = argc - 3;
	data->pipe_count = data->cmd_count - 1;
	data->infile = NULL;
	data->outfile = NULL;
	data->path = NULL;
	data->path_bin = NULL;
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
			free_all(data, TRUE);
			exit(EXIT_FAILURE);
		}
	}
}

void	fill_struct(t_pipex *data, int argc, char **argv, char **envp)
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
		cmd_i++;
	}
}

void	go_fork(t_pipex *data, int argc, char **argv, char **envp)
{
	pid_t	pid;
	
	fill_struct(data, argc, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	
	if (argc < 5)
	{
		ft_printf("- Too few arguments... -\n");
		exit(EXIT_FAILURE);
	}
	data.infile = open(argv[1], O_RDONLY);
	if (data.infile == -1)
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
	init_struct(&data, argc);
	go_fork(&data, argc, argv, envp);
}

//argv[2] = "ping google.fr"

//cmd = "ping"
//google.fr