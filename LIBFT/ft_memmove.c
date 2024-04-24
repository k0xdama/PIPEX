/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:45:32 by u4s2e0r           #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}	
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

// int	main(void)
// {
// 	printf("ft_memmove retourne : %s\n", (char *)ft_memmove(NULL, NULL, 3));
// }

//  int	main(void)
//  {
// 	const char *src = "machinchose";
// 	char dest [] = "truc muche";
// 	printf("dest était %s\n", dest);
// 	ft_memmove(dest, src, 30);
// 	printf("dest est maintenant : %s\n", dest);
//  }

// int	main(void)
// {
// 	char src[] = {67, 68 ,67 ,68, 69, 0, 45};
// 	char dest[] = {67, 67, 68, 68, 69, 0, 45};
// 	printf("%s\n", dest);
// 	ft_memmove(dest + 1, src, 2);
// 	printf("%s\n", dest);
// }