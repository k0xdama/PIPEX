/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:33 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		(*f)(i, &str[i]);
		i++;
	}
}
// static void	ft_reversechar(unsigned int i, char *c)
// {
// 	if (i % 2 == 0)
// 	{
// 		if (*c > 64 && *c < 91)
// 			*c += 32;
// 		else if (*c > 96 && *c < 123)
// 			*c -= 32;
// 	}
// }
// int	main(void)
// {
// 	char str[9] = "TRUcMUchE";
// 	ft_striteri(str, *ft_reversechar);
// 	printf("la string est maintenant %s", str);
// }