/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:42:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/26 12:20:53 by hyeongki         ###   ########.fr       */
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
	while (flag->width-- > strlen)
		ret += write(1, &c, 1);
	return (ret);
}
