/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:59:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/04/08 22:08:27 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_specifier(char spec, va_list ap)
{
	int	ret;

	ret = 0;
	if (spec == 'c')
		ret = ft_printf_char(ap);
	else if (spec == 's')
		ret = ft_printf_string(ap);
	else if (spec == 'p')
		ret = ft_printf_pointer(ap);
	else if (spec == 'd' || spec == 'i')
		ret = ft_printf_decimal(ap);
	else if (spec == 'u')
		ret = ft_printf_unsigned(ap);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret += select_specifier(*format, ap);
		}
		else
			ret += write(1, format, 1);
		format++;
	}		
	va_end(ap);
	return (ret);
}

int	main()
{
	//char	*str = "abcd";
	int ret;
	ret = printf("printf : %ld\n", 4294967294);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_printf : %u\n", 4294967294);
	printf("ret : %d\n", ret);
}
