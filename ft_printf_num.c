/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:12:41 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/30 13:55:40 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static int print_num(char *str, t_flag *flag)
//{
//	int ret;
//	int strlen;
//
//	ret = 0;
//	strlen = ft_strlen(str);
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
//	return (ret);
//}

static int print_num(char *str, t_flag *flag)
{
	int ret;
	int strlen;
	int	gap;

	ret = 0;
	strlen = ft_strlen(str);
	gap = flag->width - ft_max(strlen, flag->precision);
	if (!flag->minus && gap > 0 && (!flag->zero || (flag->zero && flag->precision)))
		while (gap-- > 0)
				ret += write(1, " ", 1);
	if (flag->num_minus)
		ret += write(1, "-", 1);
	if (flag->precision > 0)
		while (flag->precision-- > strlen)
			ret += write(1, "0", 1);
	if (flag->zero)
		while (gap-- > 0)
			ret += write(1, "0", 1);
	ret += write(1, str, strlen);
	while (gap-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}

static int convert_str(t_flag *flag, int n)
{
	char	*str;

	if (flag->only_pre)
		str = "";
	else
	{
		str = ft_itoa_base(n, flag->num_base);
		if (flag->hexa == 'x')
		{
			while (*str)
			{
				if (*str >= 'A' && *str <= 'F')
					*str += 32;
				str++;
			}
		}
	}
	return (print_num(str, flag));
}

int	ft_printf_decimal(va_list *ap, t_flag *flag)
{
	int	n;

	n = va_arg(*ap, int);
	flag->num_base = 10;
	if (n < 0)
	{
		flag->num_minus = 1;
		n *= -1;
		flag->width--;
	}
	return (convert_str(flag, n));
}

//int	ft_printf_decimal(va_list *ap, t_flag *flag)
//{
//	int	ret;
//	int	n;
//
//	ret = 0;
//	n = va_arg(*ap, int);
//	ft_putnbr_fd(n, 1);
//	if (n == -2147483648)
//		return (11);
//	if (n < 0)
//	{
//		ret++;
//		n = -n;
//	}
//	if (!n)
//		return (1);
//	while (n)
//	{
//		ret++;
//		n /= 10;
//	}
//	(void)flag;
//	return (ret);
//}

int	ft_printf_unsigned(va_list *ap, t_flag *flag)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	flag->num_base = 10;
	return (convert_str(flag , n));
}

//int	ft_printf_unsigned(va_list *ap)
//{
//	unsigned int	n;
//	int				arr[10];
//	int				i;
//	int				ret;
//	char			c;
//
//	n = va_arg(*ap, unsigned int);
//	if (!n)
//		return (write(1, "0", 1));
//	i = 0;
//	ret = 0;
//	while (n)
//	{
//		arr[i] = n % 10;
//		n /= 10;
//		i++;
//	}	
//	while (--i > -1)
//	{
//		c = arr[i] + '0';
//		ret += write(1, &c, 1);
//	}
//	return (ret);
//}

int	ft_printf_hexa(va_list *ap, char spec, t_flag *flag)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	flag->num_base = 16;
	flag->hexa = spec;
	return (convert_str(flag, n));
}

//int	ft_printf_hexa(va_list *ap, char spec)
//{
//	unsigned int	n;
//	char			hex[8];
//	int				i;
//	int				ret;
//
//	(void)spec;
//	n = va_arg(*ap, unsigned int);
//	i = 8;
//	ret = 0;
//	if (!n)
//		return (write(1, "0", 1));
//	while (n)
//	{
//		if (spec == 'x')
//			hex[--i] = HEX_LOWER[n % HEX_SIZE];
//		else
//			hex[--i] = HEX_UPPER[n % HEX_SIZE];
//		n /= HEX_SIZE;
//	}
//	while (i < 8)
//	{
//		ret += write(1, &hex[i], 1);
//		i++;
//	}
//	return (ret);
//}
