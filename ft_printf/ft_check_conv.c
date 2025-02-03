/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:17:38 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 20:04:53 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conv(char c, va_list *args, int *len, int *i)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar(va_arg(*args, int), len);
	else if (c == 's')
		res = ft_putstr(va_arg(*args, char *), len);
	else if (c == 'p')
		res = ft_pointer(va_arg(*args, size_t), len);
	else if (c == 'd' || c == 'i')
		res = ft_putnbr(va_arg(*args, int), len);
	else if (c == 'u')
		res = ft_unsigned_int(va_arg(*args, int), len);
	else if (c == 'x')
		res = ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (c == 'X')
		res = ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (c == '%')
		res = ft_putchar('%', len);
	else
		(*i)--;
	if (res == -1)
		return (-1);
	return (0);
}
