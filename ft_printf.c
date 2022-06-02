/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:59:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/06/02 15:34:38 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_specifier(char spec, va_list *ap, t_flag *flag)
{
	int	ret;

	ret = 0;
	if (spec == 'c')
		ret = ft_printf_char(ap, flag);
	else if (spec == 's')
		ret = ft_printf_string(ap, flag);
	else if (spec == 'p')
		ret = ft_printf_pointer(ap, flag);
	else if (spec == 'd' || spec == 'i')
		ret = ft_printf_decimal(ap, flag);
	else if (spec == 'u')
		ret = ft_printf_unsigned(ap, flag);
	else if (spec == 'x' || spec == 'X')
		ret = ft_printf_hexa(ap, spec, flag);
	else if (spec == '%')
		ret = ft_printf_percent(flag);
	else
		flag->error = 1;;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_flag	*flag;

	va_start(ap, format);
	ret = 0;
	flag = malloc(sizeof(t_flag));
	while (*format)
	{
		ft_memset(flag, 0, sizeof(t_flag));
		if (*format == '%')
		{
			format++;
			prework_width(flag, &format);
			prework_other(flag, &format);
			prework_precision(flag, &format);
			ret += select_specifier(*format, &ap, flag);
		}
		else
			ret += write(1, format, 1);
		format++;
		if (flag->error)
		{
			ret = -1;
			break;
		}
	}
	va_end(ap);
	free(flag);
	return (ret);
}

//int	main()
//{
//	printf("%d\n", printf("printf :%.0d\n", 420000));
//	printf("%d\n", ft_printf("ft_printf :%.0d\n", 420000));
//}
