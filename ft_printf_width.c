/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:42:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/27 18:15:00 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_padding(int strlen, t_flag *flag)
{
	int ret;
	char c;

	ret = 0;
	if (flag->zero)
		c = '0';
	else
		c = ' ';
//	if (flag->num_flag && flag->precision > strlen)
//	{
//		if (flag->num_minus || flag->zero)
//			ret += write(1, "-", 1);
//		while (flag->precision-- > strlen)
//			ret += write(1, &c, 1);
//	}
//	else
//	{
		while (flag->width-- > strlen)
			ret += write(1, &c, 1);
//	}
	return (ret);
}
