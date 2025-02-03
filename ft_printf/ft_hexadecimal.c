/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:35:19 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 21:40:05 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int u, int *len, char x_X)
{
	char	*base;

	if (x_X == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (u >= 16)
	{
		if (ft_hexadecimal(u / 16, len, x_X) == -1)
			return (-1);
	}
	if (ft_putchar(base[u % 16], len) == -1)
		return (-1);
	return (0);
}
/*int	main(void)
{
	int	len;
	unsigned int	num;
	char	format;


	len = 0;
	num = 9669;
	format = 'X';
	printf("\nEl hexadecimal de '%u', es:\n ", num);
		ft_hexadecimal(num, &len, format);
	printf("\n El total de caracteres impresos es de : '(%d)'\n", len);
	return (0);
}*/
