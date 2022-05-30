/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:01:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/27 16:54:10 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_SIZE 16

typedef struct s_flag
{
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		only_pre;
	int		num_base;
	char	hexa;
	int		num_flag;
	int		pre_flag;
	int		num_minus;
}	t_flag;

/* ft_printf.c */
int		ft_printf(const char *format, ...);
int		select_specifier(char spec, va_list *ap, t_flag *flag);

/* ft_printf_char.c */
int		ft_printf_char(va_list *ap, t_flag *flag);

/* ft_printf_string.c */
int		ft_printf_string(va_list *ap, t_flag *flag);

/* ft_printf_other.c */
int		ft_printf_pointer(va_list *ap, t_flag *flag);
int		ft_printf_percent(t_flag *flag);

/* ft_printf_num.c */
int		ft_printf_decimal(va_list *ap, t_flag *flag);
int		ft_printf_unsigned(va_list *ap, t_flag *flag);
int		ft_printf_hexa(va_list *ap, char spec, t_flag *flag);

/* ft_printf_width.c */
int		write_padding(int strlen, t_flag *flag);

/* ft_printf_prework.c */
void	prework_width(t_flag *flag, const char **format);
void	prework_precision(t_flag *flag, const char **format);

/* ft_printf_util.c */
int		check_specifier(char spec);
#endif
