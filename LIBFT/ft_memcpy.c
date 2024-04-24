/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:26:46 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	size_t				i;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char dest[100];
// 	ft_memset(dest, 'A', 100);
// 	ft_memcpy(dest, "coucou", 0);
// 	char *rtn = (char *)ft_memcpy(dest, NULL, 0);
// 	printf("%s\n", dest);
// 	printf("%s\n", rtn);
// }

// int	main(void)
// {
// 	printf("ma fonction renvoie : %s\n", (char *)ft_memcpy(NULL, NULL, 3));
// 	printf("la fonction de base renvoie : %s\n", (char *)memcpy(NULL, NULL, 3));
// }
