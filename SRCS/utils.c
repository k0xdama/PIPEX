/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:02:23 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/09 19:55:06 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

size_t	len_to_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (i);
}

void	wait_child(t_pipex *data)
{
	int	status;
	
	while (data->cmd_count)
	{
		if (waitpid(-1, &status, 0) == -1)
		{
			perror("waitpid");
			clean_exit(data, EXIT_FAILURE);
		}
		data->cmd_count--;
	}
}

void	clean_exit(t_pipex *data, int exit_code)
{
	free_parent_tab(data);
	if (exit_code == MALLOC_ERROR)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	else if (exit_code == FORK_ERROR)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (exit_code == ACCESS_ERROR)
	{
		perror("access");
		exit(EXIT_FAILURE);
	}
	else if (exit_code == PIPE_ERROR)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	else if (exit_code == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	else if (exit_code == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	close(data->old_read_fd);
}

void	free_parent_tab(t_pipex *data)
{
	int i;
	
	i = -1;
	if (data->cmds)
	{
		while (data->cmds[++i])
			free(data->cmds[i]);
		free(data->cmds);
		data->cmds = NULL;
	}
}

void	free_child_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}