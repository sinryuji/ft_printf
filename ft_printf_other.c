/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:04:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/31 17:51:22 by hyeongki         ###   ########.fr       */
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
//	unsigned long	addr;
//	int				i;
//	char			addr_hex[HEX_SIZE];
//	int				ret;
//
//	addr = (unsigned long)va_arg(*ap, void *);
//	i = HEX_SIZE;
//	while (addr > 0)
//	{
//		addr_hex[--i] = HEX_LOWER[addr % HEX_SIZE];
//		addr /= HEX_SIZE;
//	}
//	ret = write(1, "0x", 2);
//	if (i == HEX_SIZE)
//	{
//		ret += write(1, "0", 1);
//		return (ret);
//	}
//	while (i < HEX_SIZE)
//	{
//		ret += write(1, &addr_hex[i], 1);
//		i++;
//	}
//	(void)flag;
//	return (ret);
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
