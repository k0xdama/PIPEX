/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:00:12 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

int	ft_memcmp(const void *mb1, const void *mb2, size_t n)
{
	const unsigned char	*pmb1;
	const unsigned char	*pmb2;
	size_t				i;

	i = 0;
	pmb1 = (const unsigned char *)mb1;
	pmb2 = (const unsigned char *)mb2;
	while (i < n)
	{
		if (pmb1[i] != pmb2[i])
			return (pmb1[i] - pmb2[i]);
		i++;
	}
	return (0);
}
