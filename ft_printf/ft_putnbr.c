/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:57:58 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 17:10:58 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr, int *len)
{
	int	res;

	if (nbr == -2147483648)
	{
		res = write(1, "-2147483648", 11);
		(*len) += 11;
		return (res);
	}
	if (nbr < 0)
	{
		res = ft_putchar('-', len);
		res = ft_putnbr(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			res = ft_putnbr(nbr / 10, len);
		res = ft_putchar((nbr % 10) + '0', len);
	}
	return (res);
}
/*int main(void)
{
	int	result;
	int	len;

	len = 0;
	result = ft_putnbr(1955, &len);
	if (result == -1)
		return (1);
	printf(" El numero de caracteres impresos por putnbr es de '%d\n'", len);
	return (0);
}*/
