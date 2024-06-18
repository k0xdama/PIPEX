/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:48:56 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/11 15:47:58 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/get_next_line_bonus.h"

static	int	read_and_fill(char *buffer, int fd, char **reserve, int freestash)
{
	ssize_t	read_ret;
	char	*tmp;

	read_ret = 42;
	if (freestash)
		return (-1);
	if (!*reserve)
		*reserve = ft_strdup("");
	while (!ft_strchr(*reserve, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if ((read_ret < 0) || (read_ret == 0 && !**reserve))
			return (-1);
		buffer[read_ret] = '\0';
		tmp = *reserve;
		*reserve = ft_strjoin(*reserve, buffer);
		free(tmp);
		tmp = NULL;
	}
	if (!ft_strchr(*reserve, '\n') && read_ret == 0)
		return (-42);
	else
		return (read_ret);
}

static char	*build_next_line(char **reserve)
{
	char	*tmp;
	char	*line;

	line = ft_substr(*reserve, 0, (ft_strlen_gnl(*reserve, 2) + 1));
	tmp = *reserve;
	*reserve = ft_strdup((ft_strchr(*reserve, '\n') + 1));
	free(tmp);
	tmp = NULL;
	return (line);
}

static char	*free_last_call(char **reserve)
{
	free(*reserve);
	*reserve = NULL;
	return (NULL);
}

char	*get_next_line(int fd, int freestash)
{
	char		*buffer;
	char		*next_line;
	static char	*reserve[1000];
	int			check_behavior;

	check_behavior = 0;
	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	check_behavior = read_and_fill(buffer, fd, &reserve[fd], freestash);
	free(buffer);
	buffer = NULL;
	if (check_behavior == -1)
		return (free_last_call(&reserve[fd]));
	if (check_behavior == -42)
	{
		next_line = ft_strdup(reserve[fd]);
		free(reserve[fd]);
		reserve[fd] = NULL;
	}
	else
		next_line = build_next_line(&reserve[fd]);
	return (next_line);
}

// int	main(void)
// {
// 	char *result;
// 	int	fd = open("test.txt", O_RDONLY);
// 	printf("fd = %d\nBUFFER_SIZE = %d\n", fd, BUFFER_SIZE);
// 	result = get_next_line(fd);
// 	printf("GNL : %s\n", result);
// 	free(result);
// 	while(result != NULL)
// 	{
// 		result = get_next_line(fd);
// 		printf("GNL : %s\n", result);
// 	}
// 	close(fd);
// }
