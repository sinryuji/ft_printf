/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:34:56 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/25 18:39:38 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list *ap, t_flag *flag)
{
	char	c;
	int		n;
	int		ret;

	c = va_arg(*ap, int);
	n = flag->width;
	ret = 0;
	if (flag->minus)
	{
		ret += write(1, &c, 1);
		while (n-- > 1)
			ret += write(1, " ", 1);
	}
	else
	{
		while (n-- > 1)
			ret += write(1, " ", 1);
		ret += write(1, &c, 1);
	}
	return (ret);
}

