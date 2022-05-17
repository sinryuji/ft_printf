/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:34:56 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/17 15:40:13 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	return (write(1, &c, 1));
}

int	ft_printf_string(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
