/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:43:32 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/04 19:00:53 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

char *search_bin(t_pipex *data)
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
		path_to_try = ft_strjoin(tmp, (data->cmds[data->executed_cmd]));
		if (access(path_to_try, X_OK) == -1)
			tab_path++;
		else
			return (path_to_try);
	}
	return (NULL);
}

void	go_exec(t_pipex *data, char **envp)
{
	char **cmd_args;
	
	cmd_args = ft_split(((data->cmds[data->executed_cmd])), ' ');
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
	data->path_bin = search_bin(data);
	if (!data->path_bin)
		clean_exit(data, ACCESS_ERROR);
	else
		execve(data->path_bin, cmd_args, envp);
}