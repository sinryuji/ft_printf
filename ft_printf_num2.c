/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:12:47 by hyeongki          #+#    #+#             */
/*   Updated: 2022/06/01 18:56:34 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num_sign(t_flag *flag)
{
	int	ret;

	ret = 0;
	if (flag->num_minus && (!flag->macro || flag->space))
		ret += write(1, "-", 1);
	else if (flag->pointer)
		ret += write(1, "0x", 2);
	else if (flag->hash && !flag->num_zero)
	{
		if (flag->hexa == 'x')
			ret += write(1, "0x", 2);
		if (flag->hexa == 'X')
			ret += write(1, "0X", 2);
	}
	else if (flag->space)
		ret += write(1, " ", 1);
	else if (flag->plus)
		ret += write(1, "+", 1);
	return (ret);
}

int print_num(char *str, t_flag *flag)
{
	int ret;
	int strlen;
	int	gap;

	ret = 0;
	strlen = ft_strlen(str);
	gap = flag->width - ft_max(strlen, flag->precision);
	if (!flag->minus && gap > 0 && (!flag->zero || (flag->zero && flag->pre_flag)))
		while (gap-- > 0)
				ret += write(1, " ", 1);
	ret += print_num_sign(flag);
	if (flag->precision > 0)
		while (flag->precision-- > strlen)
			ret += write(1, "0", 1);
	if (flag->zero)
		while (gap-- > 0)
			ret += write(1, "0", 1);
	ret += write(1, str, strlen);
	while (gap-- > 0)
		ret += write(1, " ", 1);
	free(str);
	return (ret);
}

int convert_str(t_flag *flag, long long n)
{
	char	*str;
	int		i;
	int		ret;

	i = 0;
	if (n == 0)
		flag->num_zero = 1;
	if (flag->only_pre && (!flag->num_base || !n))
		str = ft_strdup("");
	else
	{
		if (flag->pointer)
			str = ft_ultoa_base(n, flag->num_base);
		else
			str = ft_itoa_base(n, flag->num_base);
		if (flag->hexa == 'X')
		{
			while (str[i])
			{
				if (str[i] >= 'a' && str[i] <= 'f')
					str[i] -= 32;
				i++;
			}
		}
	}
	ret = print_num(str, flag);
	return (ret);
}
