/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:45:42 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/20 14:35:48 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>

# include "libft.h"

typedef struct s_flags
{
	int			width_field;
	int			dot_field;
	int			zero;
	int			htag;
	int			hex_cap;
	int			space;
	int			plus;
	int			dash;
	int			dot;
}				t_flags;

int		ft_nbrlen(long int nb, int base, t_flags *flags);
int		ft_putchar_with_ret(char c);
int		ft_putstr(const char *str);
int		ft_miniatoi(const char *str, int *i);
void	up_struct(t_flags *flags);
int		pathfinder1(const char *str, va_list args, t_flags *flags, int *i);
void	pathfinder2(const char *str, t_flags *flags, int *i);
int		conv_specifiers(const char *str, va_list args, t_flags *flags, int *i);
int		ft_printf(const char *str, ...);
int		ft_printchar(int c, t_flags *flags);
int		ft_printstr(const char *str, t_flags *flags);
int		ft_printptr(uintptr_t ptr, t_flags *flags);
int		ft_printunbr(unsigned int nbr, t_flags *flags);
int		ft_printnbr(int nbr, t_flags *flags);
int		ft_printhexa(unsigned int nbr, t_flags *flags, char format);

#endif