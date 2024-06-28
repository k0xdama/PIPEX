/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:02:23 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/28 13:24:52 by pmateo           ###   ########.fr       */
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
			clean_exit(data, "waitpid", EXIT_FAILURE);
		}
		data->cmd_count--;
	}
}

void	clean_exit(t_pipex *data, char *err, int exit_code)
{
	if (data->cmd_and_args)
		free_child_tab(data->cmd_and_args);
	free_parent_tab(data);
	if (err)
		perror(err);
	if (exit_code == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	else if (exit_code == EXIT_FAILURE)
		exit(EXIT_FAILURE);
}
