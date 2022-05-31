/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:04:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/06/01 00:37:20 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(va_list *ap, t_flag *flag)
{
	unsigned long	n;

	n = (unsigned long)va_arg(*ap, void *);
	flag->num_base = 16;
	flag->pointer = 1;
	flag->width -= 2;
	return (convert_str(flag, n));
}
//int	ft_printf_pointer(va_list *ap, t_flag *flag)
//{
//	unsigned long	n;
//	char			*str;
//	int				strlen;
//
//	n = (unsigned long)va_arg(*ap, void *);
//	strlen = ft_ullen_base(n, 16) + 2;
//	str = malloc(sizeof(char) * (strlen + 1));
//	str[0] = '0';
//	str[1] = 'x';
//	str[strlen--] = '\0';
//	while (strlen > 1)
//	{
//		str[strlen] = HEX_LOWER[n % 16];
//		n /= 16;
//		strlen--;
//	}
//	return (print_num(str, flag));
//}

int	ft_printf_percent(t_flag *flag)
{
	int	ret;

	ret = 0;
	if (flag->minus)
	{
		ret += write(1, "%", 1);
		ret += write_padding(1, flag);
	}
	else
	{
		ret += write_padding(1, flag);
		ret += write(1, "%", 1);
	}
	return (ret);
}
