/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:35:52 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	*ft_memchr(const void *mb, int c, size_t n)
{
	const char	*pmb;
	size_t		i;

	i = 0;
	pmb = (const char *)mb;
	while (i < n)
	{
		if (pmb[i] == (char)c)
			return ((void *)&pmb[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s[] = {0, 1, 2, 3, 4, 5};
// 	printf("%p\n", ft_memchr(s, 2 + 256, 3));
// }