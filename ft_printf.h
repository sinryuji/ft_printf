/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:01:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/26 20:18:07 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_SIZE 16

typedef struct s_flag
{
	int	width;
}	t_flag;

/* ft_printf.c */
int	ft_printf(const char *format, ...);
int	select_specifier(char spec, va_list *ap);

/* ft_printf_char.c */
int	ft_printf_char(va_list *ap);
int	ft_printf_string(va_list *ap);

/* ft_printf_other.c */
int	ft_printf_pointer(va_list *ap);

/* ft_printf_num,c */
int	ft_printf_decimal(va_list *ap);
int	ft_printf_unsigned(va_list *ap);
int	ft_printf_hexa(va_list *ap, char spec);

/* ft_printf_width.c */
int	ft_printf_width(char **format);

#endif
