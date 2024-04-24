/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 02:19:29 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ldest;

	i = 0;
	j = 0;
	if (!dest || !src)
		return ((size_t) NULL);
	while (dest[i] != '\0')
		i++;
	ldest = i;
	if (size <= i)
		return (ft_strlen(src) + size);
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size <= ldest)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + ldest);
}

// int	main(void)
// {
// 	char	*dest;
// 	dest = malloc(sizeof(*dest) * 15);
// 	ft_memset(dest, 0, 15);
// 	ft_memset(dest, 'r', 15);
// 	printf("ma fonction renvoie %ld\n", 
// ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	printf("la nouvelle chaine dest est %s\n", dest);
// }
