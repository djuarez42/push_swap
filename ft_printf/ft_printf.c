/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:45:03 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 19:56:57 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list		args;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_check_conv(str[i], &args, &len, &i) == -1)
				return (-1);
			i++;
		}
		else
		{
			if (ft_putchar((char)str[i], &len) == -1)
				return (-1);
			i++;
		}
	}
	va_end(args);
	return (len);
}
