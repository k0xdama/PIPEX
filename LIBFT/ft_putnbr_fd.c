/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:24:59 by u4s2e0r           #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		nbl = nbl * -1;
		ft_putchar_fd('-', fd);
	}
	if (nbl >= 0 && nbl <= 9)
		ft_putchar_fd((nbl + 48), fd);
	else
	{
		ft_putnbr_fd((nbl / 10), fd);
		ft_putchar_fd((nbl % 10) + 48, fd);
	}
}

// int	main(void)
// {
// 	int nb = -4242;
// 	int fd = 1;
// 	ft_putnbr_fd(nb, fd);
// }