/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:42:22 by hyeongki          #+#    #+#             */
/*   Updated: 2022/05/25 16:48:37 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(char spec)
{
	if (spec == 'c' || spec == 's' || spec == 'p' || spec == 'd' || spec == 'i'
			|| spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X' || spec == '%')
		return (1);
	return (0);
}
