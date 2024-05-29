/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:02:23 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/26 17:59:01 by pmateo           ###   ########.fr       */
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
	if (merror == 1)
		ft_printf("- MALLOC ERROR ! -\n");
}