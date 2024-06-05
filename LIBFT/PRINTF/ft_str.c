/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:31 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/05 02:16:15 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int	ft_len(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (6);
	while (str[i])
		i++;
	return (i);
}

static	int	ft_putstr2(const char *str, t_flags *flags)
{
	int	printed;
	int	len;

	printed = 0;
	len = ft_len(str);
	if (flags->dot == 1 && flags->dot_field < len)
		len = flags->dot_field;
	if (str == NULL)
	{
		if (flags->dot == 1 && (flags->dot_field < 6))
			return (0);
		else
		{
			printed += write(flags->fd, "(null)", 6);
			return (printed);
		}
	}
	else
	{
		printed += write(flags->fd, str, len);
		return (printed);
	}
}

int	ft_printstr(const char *str, t_flags *flags)
{
	int	printed;
	int	printed_width;
	int	precision;
	int	width_size;

	printed = 0;
	printed_width = 0;
	precision = flags->dot_field;
	if (precision < ft_len(str) && flags->dot == 1)
		width_size = flags->width_field - (precision);
	else
		width_size = flags->width_field - (ft_len(str));
	if (flags->dash == 1)
		printed += ft_putstr2(str, flags);
	while (printed_width < width_size)
		printed_width += ft_putchar_with_ret(flags->fd, ' ');
	if (flags->dash == 0)
		printed += ft_putstr2(str, flags);
	return (printed + printed_width);
}
