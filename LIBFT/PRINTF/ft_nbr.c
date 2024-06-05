/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:36:05 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/05 02:12:55 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int	is_neg(int nbr)
{
	if (nbr < 0)
		return (1);
	else
		return (0);
}

static int	ft_putnbr(int nbr, t_flags *flags, int callnb)
{
	long	nbl;
	int		printed;

	nbl = nbr;
	printed = ft_nbrlen(nbl, 10, flags);
	if (nbr == 0 && (flags->dot == 1 && flags->dot_field == 0 && callnb == 1))
		return (0);
	if (nbl < 0)
		nbl *= -1;
	if (nbl >= 0 && nbl <= 9)
		ft_putchar_with_ret(flags->fd, nbl + 48);
	if (nbl > 9)
	{
		ft_putnbr(nbl / 10, flags, ++callnb);
		ft_putnbr(nbl % 10, flags, ++callnb);
	}
	return (printed);
}

static int	dash_off(int nbr, t_flags *flags, int *precision, int *width_size)
{
	int	printed;
	int	printed_prec;

	printed = 0;
	printed_prec = 0;
	while (printed < (*width_size) && (flags->zero == 0 || flags->dot == 1))
		printed += ft_putchar_with_ret(flags->fd, ' ');
	if (nbr >= 0 && (flags->plus == 1 && flags->zero == 1 && flags->dot == 0))
	{
		printed += ft_putchar_with_ret(flags->fd, '+');
		flags->plus = 0;
	}
	if (nbr < 0 && (flags->dot == 0))
		ft_putchar_with_ret(flags->fd, '-');
	while (printed < (*width_size) && (flags->zero == 1 && flags->dot == 0))
		printed += ft_putchar_with_ret(flags->fd, '0');
	if (nbr >= 0 && flags->plus == 1)
		printed += ft_putchar_with_ret(flags->fd, '+');
	if (nbr < 0 && flags->dot == 1)
		ft_putchar_with_ret(flags->fd, '-');
	while (printed_prec < (*precision))
		printed_prec += ft_putchar_with_ret(flags->fd, '0');
	printed += ft_putnbr(nbr, flags, 1);
	return (printed + printed_prec);
}

static int	dash_on(int nbr, t_flags *flags, int *precision, int *width_size)
{
	int	printed;
	int	printed_prec;
	int	printed_width;

	printed = 0;
	printed_prec = 0;
	printed_width = 0;
	if (flags->plus == 1)
		printed += ft_putchar_with_ret(flags->fd, '+');
	if (nbr < 0)
		ft_putchar_with_ret(flags->fd, '-');
	while (printed_prec < (*precision))
		printed_prec += ft_putchar_with_ret(flags->fd, '0');
	printed += ft_putnbr(nbr, flags, 1);
	while (printed_width < (*width_size))
		printed_width += ft_putchar_with_ret(flags->fd, ' ');
	return (printed + printed_prec + printed_width);
}

int	ft_printnbr(int nbr, t_flags *flags)
{
	int	printed;
	int	nbrlen;
	int	prec;
	int	width;

	printed = 0;
	nbrlen = ft_nbrlen(nbr, 10, flags);
	prec = flags->dot_field;
	if (prec <= nbrlen)
		prec = 0;
	if (flags->dot == 1 && prec > nbrlen)
		prec -= nbrlen;
	width = flags->width_field - (nbrlen + prec + flags->plus
			+ flags->space + is_neg(nbr));
	if (flags->space == 1 && nbr >= 0)
		printed += ft_putchar_with_ret(flags->fd, ' ');
	if (flags->dash == 1)
		printed += dash_on(nbr, flags, &prec, &width);
	else if (flags->dash == 0)
		printed += dash_off(nbr, flags, &prec, &width);
	return (printed + is_neg(nbr));
}
