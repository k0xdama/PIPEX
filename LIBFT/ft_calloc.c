/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:01:42 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buffer;
	size_t	i;
	size_t	tmp;

	i = 0;
	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	tmp = num * size;
	if ((tmp / size) != num)
		return (NULL);
	buffer = (void *)malloc(size * num);
	if (!buffer)
		return (NULL);
	while (i < num * size)
	{
		((unsigned char *)buffer)[i] = 0;
		i++;
	}
	return (buffer);
}
