/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:41:27 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !tofind)
		return (NULL);
	if (!tofind || !tofind[0])
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		while (str[i + j] == tofind[j] && i + j < n && str[i + j] && tofind[j])
			j++;
		if (tofind[j] == '\0')
			return ((char *)str + i);
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *str = "trouvemoi";
// 	const char *tofind = "moi";
// 	printf("ft_strnstr retourne %s", ft_strnstr(str, tofind, 9));
// }
// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("", "", 0));
// }