/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:39:46 by hyeongki          #+#    #+#             */
/*   Updated: 2022/06/02 15:49:15 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int write_string(char *str, t_flag *flag)
//{
//	int ret;
//	int strlen;
//
//	ret = 0;
//	strlen = ft_strlen(str);
//	if (!flag->num_flag && flag->precision < strlen && flag->precision > 0)
//		strlen = flag->precision;
//	if (*str == '-' && (flag->pre_flag || flag->zero))
//	{
//		ret += write(1, str, 1);
//		str++;
//		strlen--;
//		flag->width--;
//	}
//	if (flag->minus)
//	{
//		ret += write(1, str, strlen);
//		ret += write_padding(strlen, flag);
//	}
//	else
//	{
//		ret += write_padding(strlen, flag);
//		ret += write(1, str, strlen);
//	}
//	return (ret);
//}

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

int	ft_printf_percent(t_flag *flag)
{
	int	ret;

	ret = 0;
	if (flag->minus)
	{
		ret += write(1, "%", 1);
		ret += write_padding(1, flag);
	}
	else
	{
		ret += write_padding(1, flag);
		ret += write(1, "%", 1);
	}
	return (ret);
}

int	ft_printf_string(va_list *ap, t_flag *flag)
{
	char	*str;
	int		ret;	
	int		strlen;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	if (flag->only_pre)
		str = "";
	ret = 0;
	strlen = ft_strlen(str);
	if (flag->precision < strlen && flag->precision > 0)
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
