/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:03:09 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/29 20:53:51 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

void	init_struct(t_pipex *data, int argc)
{
	int	i;

	i = 0;
	data->cmd_count = argc - 3;
	data->executed_cmd = 0;
	data->pipe_count = data->cmd_count - 1;
	data->infile = 0;
	data->outfile = 0;
	data->path_bin = NULL;
	data->cmds = malloc(data->cmd_count * sizeof(char *));
	if (!data->cmds)
		exit(EXIT_FAILURE);
	data->is_heredoc = 0;
	data->child_pid = 0;
	data->fd[0] = 0;
	data->fd[1] = 0;
}

void	fill_struct(t_pipex *data, int argc, char **argv)
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