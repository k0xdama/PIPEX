/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:03:09 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/11 16:21:29 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

void	init_struct(t_pipex *data, int argc)
{
	data->cmd_count = argc - 3;
	data->executed_cmd = 0;
	data->pipe_count = data->cmd_count - 1;
	data->infile = 0;
	data->outfile = 0;
	data->path_bin = NULL;
	data->path_to_try = NULL;
	data->tab_path = NULL;
	data->cmds = malloc((data->cmd_count + 1) * sizeof(char *));
	if (!data->cmds)
		exit(EXIT_FAILURE);
	data->is_heredoc = 0;
	data->heredoc_fd = 0;
	data->limiter = NULL;
	data->child_pid = 0;
	data->fd[0] = 0;
	data->fd[1] = 0;
	data->old_read_fd = -1;
}

void	fill_struct(t_pipex *data, int argc, char **argv)
{
	int	arg_i;
	int	cmd_i;

	arg_i = 2;
	cmd_i = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		data->is_heredoc = 1;
		data->cmd_count = argc - 4;
		arg_i++;
	}
	while (arg_i != (argc - 1))
	{
		data->cmds[cmd_i] = ft_strdup(argv[arg_i]);
		arg_i++;
		cmd_i++;
	}
	data->cmds[cmd_i] = NULL;
}
