/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:39:46 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/27 13:28:19 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_string(char *str, t_flag *flag)
{
	int ret;
	int strlen;

	ret = 0;
	strlen = ft_strlen(str);
	if (!flag->num_flag && flag->precision < strlen && flag->precision > 0)
		strlen = flag->precision;
	if (flag->minus)
	{
		ret += write(1, str ,strlen);
		ret += write_padding(strlen, flag);
	}
	else
	{
		ret += write_padding(strlen, flag);
		ret += write(1, str, strlen);
	}
	return (ret);
}


int	ft_printf_string(va_list *ap, t_flag *flag)
{
	char	*str;
//	int		ret;	
//	int		strlen;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	if (flag->only_pre)
		str = "";
//	ret = 0;
//	strlen = ft_strlen(str);
//	if (flag->precision < strlen && flag->precision > 0)
//		strlen = flag->precision;
//	if (flag->minus)
//	{
//		ret += write(1, str ,strlen);
//		ret += write_padding(strlen, flag);
//	}
//	else
//	{
//		ret += write_padding(strlen, flag);
//		ret += write(1, str, strlen);
//	}
	return (write_string(str, flag));
}
