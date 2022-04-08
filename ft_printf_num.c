/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:12:41 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/08 22:05:35 by hyeongki         ###   ########.fr       */
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
	while (n)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}

int	ft_printf_unsigned(va_list ap)
{
	unsigned int	n;
	int				arr[10];
	int				i;
	int				ret;
	char			c;

	n = va_arg(ap, unsigned int);
	if (!n)
		return (write(1, "0", 1));
	i = 0;
	ret = 0;
	while (n)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}	
	while (--i > -1)
	{
		c = arr[i] + '0';
		ret += write(1, &c, 1);
	}
	return (ret);
}
