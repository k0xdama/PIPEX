/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 05:33:59 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		else
			i++;
	}
	if (str[i] == c)
		return ((char *)str + i);
	return (NULL);
}

// int	main(void)
// {
// 	int c = '\n';
// 	char *str = "ado\nA qui l'on pr";
// 	printf("ma fonction retourne %s\n", ft_strchr(str, c));
// 	printf("le pointeur retourné à cette adresse : %p\n", ft_strchr(str, c));
// }

// int	main(void)
// {
// 	char s[] = "tripouille";
// 	printf("ma fonction retourne %s\n", ft_strchr(s, 't' + 256));
// 	printf("la fonction de base retourne %s\n", strchr(s, 't' + 256));	
// }
