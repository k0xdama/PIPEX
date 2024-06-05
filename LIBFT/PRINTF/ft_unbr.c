/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:40 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/05 02:16:45 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int	ft_uputnbr(unsigned int nbr, t_flags *flags, int callnb)
{
	unsigned long	nbl;
	int				len;

	if (nbr == 0 && (flags->dot == 1 && flags->dot_field == 0 && callnb == 1))
		return (0);
	nbl = nbr;
	len = ft_nbrlen(nbr, 10, flags);
	if (nbl <= 9)
		ft_putchar_with_ret(flags->fd, nbl + 48);
	if (nbl > 9)
	{
		ft_uputnbr(nbl / 10, flags, ++callnb);
		ft_uputnbr(nbl % 10, flags, ++callnb);
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
	while (printed_prec < (*prec))
		printed_prec += ft_putchar_with_ret(flags->fd, '0');
	printed += ft_uputnbr(nbr, flags, 1);
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
	while (printed_prec < (*prec) && flags->dot == 1)
		printed_prec += ft_putchar_with_ret(flags->fd, '0');
	while (printed < (*width) && flags->zero == 1)
		printed += ft_putchar_with_ret(flags->fd, '0');
	printed += ft_uputnbr(nbr, flags, 1);
	return (printed + printed_prec);
}

int	ft_printunbr(unsigned int nbr, t_flags *flags)
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
	width = flags->width_field - (nbrlen + prec);
	if (flags->dash == 1)
		printed += dash_on(nbr, flags, &prec, &width);
	else if (flags->dash == 0)
		printed += dash_off(nbr, flags, &prec, &width);
	return (printed);
}

// int	main(void)
// {
// 	unsigned int nb = 4568001447;
// 	int ret1 = ft_uputnbr(nb);
// 	printf("\n");
// 	int ret2 = printf("%u", nb);
// 	printf("\n");
// 	printf("ret1 = %d\n", ret1);
// 	printf("ret2 = %d\n", ret2);
// }
