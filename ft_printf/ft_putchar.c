/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:26:52 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 16:59:55 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch, int *len)
{
	if (write(1, &ch, 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}
/*int main(void)
{
int	len;
	int	result;

	len = 0;
	result = ft_putchar('H', &len);
	if (result == -1)
		return(1);
	result = ft_putchar('o', &len);
	if (result == -1)
		return(1);
	result = ft_putchar('l', &len);
        if (result == -1)
                return(1);
        result = ft_putchar('a', &len);
        if (result == -1)
                return(1);
	printf (" y el lenght es de '%d'\n", len);
	return (0);
}*/
