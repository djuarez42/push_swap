/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:08:09 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 17:23:34 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_int(unsigned int u, int *len)
{
	if (u > 9)
		if (ft_unsigned_int(u / 10, len) == -1)
			return (-1);
	if (ft_putchar ((u % 10) + '0', len) == -1)
		return (-1);
	return (0);
}
/*int main(void)
{
	unsigned int	number;
	int	len;

	number = 9669;
	len = 0;
	
	if (ft_unsigned_int(number, &len) == -1)
	{
	printf("error al imprimir el numero\n");
		return (-1);
	}
	printf(" el numero de caracteres impresos es: %d\n", len);
}*/
