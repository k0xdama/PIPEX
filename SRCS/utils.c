/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:02:23 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/25 19:50:11 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

void	clean_exit(int exit_code)
{
	
}

void	free_all(t_pipex *data, int merror)
{
	int i;
	
	i = 0;
	if (data->cmds)
	{
		while (data->cmds[i++])
			free(data->cmds[i]);
		free(data->cmds);
	}
	// i = 0;
	// if (data->pipe_tab)
	// {
	// 	while (data->pipe_tab[i++])
	// 		free(data->cmds[i]);
	// 	free(data->pipe_tab);
	// }
	if (merror == 1)
		ft_printf("- MALLOC ERROR ! -\n");
}