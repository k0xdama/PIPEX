/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:56:20 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

static void	reversestr(char *str, int len)
{
	int			i;
	int			j;
	char		tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
	i++;
	j--;
	}
}

static void	fill(char *str, long ln, int n)
{
	int	digit;
	int	i;

	i = 0;
	if (ln == 0)
		str[0] = '0';
	while (ln != 0)
	{
		digit = ln % 10;
		str[i] = digit + 48;
		ln = ln / 10;
		i++;
	}
	if (n < 0)
		str[i] = '-';
}

static int	digit_count(long ln)
{
	int	count;

	count = 0;
	if (ln == 0)
		count = 1;
	while (ln)
	{
		ln /= 10;
		count++;
	}
	return (count);
}

static int	isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	long	ln;
	int		size;
	char	*str;

	ln = n;
	if (ln < 0)
		ln *= -1;
	size = digit_count(ln) + isneg(n);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	fill(str, ln, n);
	if (str[0] != '0' || size != 1)
		reversestr(str, size);
	str[size] = '\0';
	return (str);
}
// int	main(void)
// {
// 	int nb = -4200;
// 	printf("ma fonction retourne : %s\n", ft_itoa(nb));
// 	return (0);
// }
// #include <limits.h>
// int	main(void)
// {
// 	printf("%s\n", ft_itoa(543000));
// }
