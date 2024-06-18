/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:50:42 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/11 16:23:03 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/pipex.h"

void	handle_heredoc(t_pipex *data)
{
	int		fd_heredoc;
	char	*buffer;
	char	*tmp;

	buffer = NULL;
	tmp = data->limiter;
	data->limiter = ft_strjoin(data->limiter, "\n");
	free(tmp);
	fd_heredoc = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		ft_printf(2, "> ");
		buffer = get_next_line(0, 0);
		if (!buffer)
			break ;
		if (ft_strcmp(data->limiter, buffer) == 0)
			break ;
		ft_printf(fd_heredoc, "%s", buffer);
		free(buffer);
	}
	get_next_line(0, 1);
	free(buffer);
	buffer = NULL;
	free(data->limiter);
	close(fd_heredoc);
}
