/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:55:00 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/20 05:30:02 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

void	check_bin_path(t_pipex *data)
{
	data->path_bin = ft_substr(data->cmds[data->executed_cmd], 0,
			len_to_space(data->cmds[data->executed_cmd]));
	if (access(data->path_bin, X_OK) == -1)
	{
		free(data->path_bin);
		data->path_bin = NULL;
	}
}

char	*search_bin(t_pipex *data)
{
	char	*bin;
	char	*tmp;
	int		i;

	i = 0;
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
			free(data->path_to_try);
		}
		else
			return (data->path_to_try);
	}
	return (free_child_tab(data->tab_path), NULL);
}