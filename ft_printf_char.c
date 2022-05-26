/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:34:56 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/26 16:14:44 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list *ap, t_flag *flag)
{
	char	c;
	int		ret;

	c = va_arg(*ap, int);
	ret = 0;
	if (flag->minus)
	{
		ret += write(1, &c ,1);
		ret += write_padding(1, flag);
	}
	else
	{
		ret += write_padding(1, flag);
		ret += write(1, &c, 1);
	}
	return (ret);
}

