/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:43 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/05 02:11:38 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int	ft_puthexa(unsigned int nbr, int bool, t_flags *flags, int callnb)
{
	int				len;
	unsigned long	nbl;
	char			*basemaj;
	char			*basemin;

	len = ft_nbrlen(nbr, 16, flags);
	nbl = nbr;
	basemaj = "0123456789ABCDEF";
	basemin = "0123456789abcdef";
	if (nbr == 0 && (flags->dot == 1 && flags->dot_field == 0 && callnb == 1))
		return (0);
	if (nbl < 16 && bool == 0)
		ft_putchar_with_ret(flags->fd, basemin[nbl]);
	else if (nbl < 16 && bool == 1)
		ft_putchar_with_ret(flags->fd, basemaj[nbl]);
	if (nbl >= 16)
	{
		ft_puthexa(nbl / 16, bool, flags, ++callnb);
		ft_puthexa(nbl % 16, bool, flags, ++callnb);
	}
	return (len);
}

static int	dash_on(unsigned int nbr, t_flags *flags, int *prec, int *width)
{
	int	printed;
	int	printed_prec;
	int	printed_width;

	printed = 0;
	printed_prec = 0;
	printed_width = 0;
	if (flags->htag == 2 && nbr > 0)
	{
		if (flags->hex_cap == 1)
			printed += ft_putstr(flags->fd, "0X");
		else
			printed += ft_putstr(flags->fd, "0x");
	}
	while (printed_prec < (*prec) && flags->dot == 1)
		printed_prec += ft_putchar_with_ret(flags->fd, '0');
	if (flags->hex_cap == 1)
		printed += ft_puthexa(nbr, 1, flags, 1);
	else
		printed += ft_puthexa(nbr, 0, flags, 1);
	while (printed_width < (*width))
		printed_width += ft_putchar_with_ret(flags->fd, ' ');
	return (printed + printed_prec + printed_width);
}

static int	dash_off(unsigned int nbr, t_flags *flags, int *prec, int *width)
{
	int	printed;
	int	printed_prec;

	printed = 0;
	printed_prec = 0;
	while (printed < (*width)
		&& (flags->zero == 0 || flags->dot == 1))
		printed += ft_putchar_with_ret(flags->fd, ' ');
	if (flags->htag == 2 && nbr > 0)
	{
		if (flags->hex_cap == 1)
			printed += ft_putstr(flags->fd, "0X");
		else
			printed += ft_putstr(flags->fd, "0x");
	}
	while (printed_prec < (*prec) && flags->dot == 1)
		printed_prec += ft_putchar_with_ret(flags->fd, '0');
	while (printed < (*width) && flags->zero == 1)
		printed += ft_putchar_with_ret(flags->fd, '0');
	if (flags->hex_cap == 1)
		printed += ft_puthexa(nbr, 1, flags, 1);
	else
		printed += ft_puthexa(nbr, 0, flags, 1);
	return (printed + printed_prec);
}

int	ft_printhexa(unsigned int nbr, t_flags *flags, char format)
{
	int	printed;
	int	nbrlen;
	int	precision;
	int	width_size;

	printed = 0;
	nbrlen = ft_nbrlen(nbr, 16, flags);
	precision = flags->dot_field;
	if (precision <= nbrlen)
		precision = 0;
	if (flags->dot == 1 && precision > nbrlen)
		precision -= nbrlen;
	width_size = flags->width_field - (nbrlen + precision);
	if (format == 'X')
		flags->hex_cap = 1;
	if (flags->dash == 1)
		printed += dash_on(nbr, flags, &precision, &width_size);
	else if (flags->dash == 0)
		printed += dash_off(nbr, flags, &precision, &width_size);
	return (printed);
}
