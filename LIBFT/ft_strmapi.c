/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:32:13 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*outstr;
	size_t	i;

	i = 0;
	if (s == NULL || *f == NULL)
		return (NULL);
	outstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!outstr)
		return (NULL);
	while (s[i])
	{
		outstr[i] = (*f)(i, s[i]);
		i++;
	}
	outstr[i] = '\0';
	return (outstr);
}
// static char	ft_reversechar(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 	{
// 		if (c > 64 && c < 91)
// 			c += 32;
// 		else if (c > 96 && c < 123)
// 			c -= 32;
// 	}
// 	return (c);
// }
// int	main(void)
// {
// 	char str[9] = "TRUcMUchE";
// 	printf("ft_strmapi renvoie : %s\n", ft_strmapi(str, ft_reversechar));
// }