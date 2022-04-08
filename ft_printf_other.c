/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:04:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/08 23:40:34 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(va_list ap)
{
	long long	addr;
	int			i;
	char		addr_hex[HEX_SIZE];
	int			ret;

	addr = (long long)va_arg(ap, void *);
	i = HEX_SIZE;
	while (addr > 0)
	{
		addr_hex[--i] = HEX_LOWER[addr % HEX_SIZE];
		addr /= HEX_SIZE; 
	}
	ret = write(1, "0x", 2);
	while (i < HEX_SIZE)
	{
		ret += write(1, &addr_hex[i], 1);
		i++;
	}
	return (ret);
}
