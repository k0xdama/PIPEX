/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:43:32 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/19 20:10:13 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

char	*check_bin_path(t_pipex *data)
{
	data->path_bin = ft_substr(data->cmds[data->executed_cmd], 0,
			len_to_space(data->cmds[data->executed_cmd]));
	if (access(data->path_bin, X_OK) == -1)
	{
		free(data->path_bin);
		return (NULL);
	}
	else
		return (data->path_bin);
}

char	*search_bin(t_pipex *data)
{
	char	*bin;
	char	*tmp;
	int		i;

	i = 0;
	data->tab_path = ft_split(data->all_path, ':');
	if (!data->tab_path)
		clean_exit(data, MALLOC_ERROR);
	while (data->tab_path[i])
	{
		tmp = ft_strjoin(data->tab_path[i], "/");
		bin = ft_substr(data->cmds[data->executed_cmd], 0,
				len_to_space(data->cmds[data->executed_cmd]));
		data->path_to_try = ft_strjoin(tmp, bin);
		free(tmp);
		free(bin);
		if (access(data->path_to_try, X_OK) == -1)
		{
			i++;
			dprintf(2, "ntm %d\n", i);
			free(data->path_to_try);
		}
		else
			return (data->path_to_try);

			
	}
	return (free_child_tab(data->tab_path), NULL);
}

void	go_exec2(t_pipex *data, char **cmd_args, char **envp)
{
	if (!data->path_bin && !data->all_path)
	{
		free(data->path_bin);
		free_child_tab(cmd_args);
		ft_printf(2, "\033[1;5;31m - Environment variable doesn't exist, ");
		ft_printf(2, "please specify absolute path. - \n\033[0m");
		clean_exit(data, EXIT_FAILURE);
	}
	if (!data->path_bin && data->all_path)
	{
		free(data->path_bin);
		free_child_tab(cmd_args);
		clean_exit(data, ACCESS_ERROR);
	}
	else
	{
		if (execve(data->path_bin, cmd_args, envp) == -1)
		{
			
		}
	}
}

void	go_exec(t_pipex *data, char **envp)
{
	char	**cmd_args;

	// print_tab(data->cmds);
	cmd_args = ft_split(((data->cmds[data->executed_cmd])), ' ');
	// print_tab(cmd_args);
	if (!cmd_args)
		clean_exit(data, EXIT_FAILURE);
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
	if (ft_strchr(data->cmds[data->executed_cmd], '/'))
		data->path_bin = check_bin_path(data);
	else if (data->all_path)
		data->path_bin = search_bin(data);
	go_exec2(data, cmd_args, envp);
}
