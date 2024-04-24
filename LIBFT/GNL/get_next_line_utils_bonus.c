/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:48:52 by pmateo            #+#    #+#             */
/*   Updated: 2024/04/18 23:15:46 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c == 1)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (str[i] != '\n')
			i++;
		return (i);
	}
}
