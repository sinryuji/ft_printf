/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:39:46 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/25 19:10:37 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	common_string(char *str, t_flag *flag)
{
	int ret;
	int strlen;

	ret = 0;
	strlen = ft_strlen(str);
	if (flag->minus)
	{
		ret += write(1, str, strlen);
		while (flag->width-- > strlen)
			ret += write(1, " ", 1);
	}
	else
	{
		while (flag->width-- > strlen)
			ret += write(1, " ", 1);
		ret += write(1, str, strlen);
	}
	return (ret);
}

int pre_string(char *str, t_flag *flag)
{
	int ret;
	int	strlen;

	ret = 0;
	strlen = ft_strlen(str);
	if (flag->precision < strlen)
		strlen = flag->precision;
	if (flag->minus)
	{
		ret += write(1, str, strlen);
		while (flag->width-- > strlen)
			ret += write(1, " ", 1);
	}
	else
	{
		while (flag->width-- > strlen)
			ret += write(1, " ", 1);
		ret += write(1, str, strlen);
	}
	return (ret);
}

int	ft_printf_string(va_list *ap, t_flag *flag)
{
	char	*str;
//	int		n;
//	int		ret;
//	int		strlen;
//	int		precision;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	if (flag->only_pre)
		str = "";
	if (flag->pre_flag)
		return (pre_string(str, flag));
	return (common_string(str, flag));

//	n = flag->width;
//	ret = 0;
//	strlen = ft_strlen(str);
//	if (flag->pre_flag && flag->precision < strlen)
//	{
//		precision = flag->precision;
//		n += flag->width - flag->precision;
//	}
//	else
//		precision = strlen;
//	if (flag->minus)
//	{
//		ret += write(1, str, precision);
//		while (n-- > strlen)
//			ret += write(1, " ", 1);
//	}
//	else
//	{
//		while (n-- > strlen)
//			ret += write(1, " ", 1);
//		ret += write(1, str, precision);
//	}
//	return (ret);
}

