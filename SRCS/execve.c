/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:43:32 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/25 14:39:33 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

static void	search_path(t_pipex *data, char **envp)
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
	if (data->all_path)
	{
		data->tab_path = ft_split(data->all_path, ':');
		if (!data->tab_path)
			clean_exit(data, "malloc", EXIT_FAILURE);
	}
}

void	exec(t_pipex *data, char **envp)
{
	if (!data->path_bin && !data->all_path)
	{
		free(data->path_bin);
		ft_printf(2, "\033[1;5;31m - Environment variable doesn't exist, ");
		ft_printf(2, "please specify absolute path. - \n\033[0m");
		clean_exit(data, NULL, EXIT_FAILURE);
	}
	else if (!data->path_bin && data->all_path)
	{
		free(data->path_bin);
		clean_exit(data, "access", EXIT_FAILURE);
	}
	else
	{
		if (execve(data->path_bin, data->cmd_and_args, envp) == -1)
		{
			free(data->path_bin);
			free_child_tab(data->tab_path);
			clean_exit(data, "execve", EXIT_FAILURE);
		}
	}
}

void	go_exec(t_pipex *data, char **envp)
{
	data->cmd_and_args = ft_split(((data->cmds[data->executed_cmd])), ' ');
	if (!data->cmd_and_args)
		clean_exit(data, "malloc", EXIT_FAILURE);
	if (ft_strchr(data->cmds[data->executed_cmd], '/'))
		check_bin_path(data);
	else
	{
		if (*envp)
			search_path(data, envp);
		if (data->all_path)
			data->path_bin = search_bin(data);
	}
	exec(data, envp);
}
