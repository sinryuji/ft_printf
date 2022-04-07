/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:12:41 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/08 00:48:12 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_decimal(va_list ap)
{
	int	ret;
	int	n;
	
	ret = 0;
	n = va_arg(ap, int);
	ft_putnbr_fd(n, 1);	
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		ret++;
		n = -n;
	}
	while (n > 0)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}
