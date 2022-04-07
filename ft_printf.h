/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:01:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/07 21:26:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

# define HEX "0123456789abcdef"

// ft_printf.c
int	ft_printf(const char *format, ...);
int	select_specifier(char spec, va_list ap);

// ft_printf_char.c
int	ft_printf_char(va_list ap);
int	ft_printf_string(va_list ap);

// ft_printf_other.c
int	ft_printf_pointer(va_list ap);

#endif
