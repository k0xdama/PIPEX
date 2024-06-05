/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:36 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/05 02:15:34 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_ptrlen(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static int	ft_putptr(uintptr_t ptr, t_flags *flags)
{
	int		len;
	char	*base;

	len = ft_ptrlen((unsigned long)ptr);
	base = "0123456789abcdef";
	if (ptr < 16)
		ft_putchar_with_ret(flags->fd, base[ptr]);
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, flags);
		ft_putptr(ptr % 16, flags);
	}
	return (len);
}

static int	dash_on(uintptr_t ptr, int *width_size, t_flags *flags)
{
	int	printed;
	int	printed_width;

	printed = 0;
	printed_width = 0;
	if (ptr == 0)
		printed += ft_putstr(flags->fd, "(nil)");
	else
	{
		printed += ft_putstr(flags->fd, "0x");
		printed += ft_putptr(ptr, flags);
		while (printed_width < (*width_size))
			printed_width += ft_putchar_with_ret(flags->fd, ' ');
	}
	return (printed + printed_width);
}

static int	dash_off(uintptr_t ptr, int *width_size, t_flags *flags)
{
	int	printed;

	printed = 0;
	while (printed < (*width_size))
		printed += ft_putchar_with_ret(flags->fd, ' ');
	if (ptr == 0)
		printed += ft_putstr(flags->fd, "(nil)");
	else
	{
		printed += ft_putstr(flags->fd, "0x");
		printed += ft_putptr(ptr, flags);
	}
	return (printed);
}

int	ft_printptr(uintptr_t ptr, t_flags *flags)
{
	int	printed;
	int	ptrlen;
	int	width_size;

	printed = 0;
	if (ptr == 0)
		ptrlen = 5;
	else
		ptrlen = ft_ptrlen(ptr);
	width_size = flags->width_field - (ptrlen + 2);
	if (ptr == 0)
		width_size += 2;
	if (flags->dash == 1)
		printed += dash_on(ptr, &width_size, flags);
	else if (flags->dash == 0)
		printed += dash_off(ptr, &width_size, flags);
	return (printed);
}

// int main(void)
// {
//     char *str = "string";
//     char **ptr;
//     ptr = &str;
//     // printf("%p\n", ptr);
//     write(1, &ptr, );
// }
