/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:40:51 by hyeongki          #+#    #+#             */
/*   Updated: 2022/06/01 13:14:32 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prework_width(t_flag *flag, const char **format)
{
	int	n;

	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			flag->minus = 1;
		else
			flag->zero = 1;
		(*format)++;
	}
	if (flag->minus && flag->zero)
		flag->zero = 0;	
	n = ft_atoi(*format);
	flag->width = n;
	while (n)
	{
		n /= 10;
		(*format)++;
	}
}

void	prework_precision(t_flag *flag, const char **format)
{
	int	n;

	if (**format == '.')
	{
		(*format)++;
		flag->pre_flag = 1;
		if (ft_isdigit(**format))
		{
			n = ft_atoi(*format);
			flag->precision = n;
			if (!n)
				flag->only_pre = 1;
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			flag->only_pre = 1;
	}
}
