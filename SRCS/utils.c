/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:02:23 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/29 20:50:15 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

void	clean_exit(t_pipex *data, int exit_code)
{
	free_all(data);
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
}

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
}