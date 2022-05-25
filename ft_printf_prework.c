/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:40:51 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/25 19:29:50 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prework_width(t_flag *flag, const char **format)
{
	int	n;

	if (**format == '-')
	{
		flag->minus = 1;
		(*format)++;
	}
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
		if (ft_isdigit(**format))
		{
			flag->pre_flag = 1;
			n = ft_atoi(*format);
			flag->precision = n;
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			flag->only_pre = 1;
	}
}
