/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:04:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/07 21:38:50 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(va_list ap)
{
	long long	addr;
	int			i;
	char		addr_hex[16];
	int			ret;

	addr = (long long)va_arg(ap, void *);
	i = 16;
	while (addr > 0)
	{
		addr_hex[--i] = HEX[addr % 16];
		addr /= 16; 
	}
	write(1, "0x", 2);
	ret = 18 - i;
	while (i < 16)
	{
		write(1, &addr_hex[i], 1);
		i++;
	}
	return (ret);
}
