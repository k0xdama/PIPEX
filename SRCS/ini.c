/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:03:09 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/18 23:03:52 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

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
	while (arg_i != (argc - 1))
	{
		data->cmds[cmd_i] = ft_strdup(argv[arg_i]);
		arg_i++;
		cmd_i++;
	}
}