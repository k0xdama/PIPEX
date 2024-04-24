/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 05:35:19 by pmateo            #+#    #+#             */
/*   Updated: 2024/04/18 23:16:00 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

int	ft_atoi(const char *str, int *error)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while ((str[i] == 43 || str[i] == 45)
		&& (str[i +1] >= '0' && str[i +1] <= '9'))
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		*error = 1;
	return (result);
}

// int	main(void)
// {
// 	char *str = "  -4234bd";
// 	printf("ma fonction renvoie %d\n", ft_atoi(str));
// 	printf("la fonction de base renvoie %d", atoi(str));
// }