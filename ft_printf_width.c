/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:42:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/22 15:02:14 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_width(char **format)
{
	int	n;
	int	i;
	int	ret;

	if (**format < '0' || **format > '9')
		return (0);
	n = ft_atoi(*format);
	i = 0;
	ret = 0;
	while (i < n)
	{
		ret += write(1, " ", 1);
		i++;
	}
	while (n)
	{
		(*format)++;
		n /= 10;
	}
	return (ret);
}
