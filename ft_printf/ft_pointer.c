/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:07 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/08 17:07:04 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(size_t ptr, int *len)
{
	char	*base;

	if (ptr == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		(*len) += 5;
		return (0);
	}
	base = "0123456789abcdef";
	if (ptr < 16)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		(*len) += 2;
	}
	if (ptr >= 16)
	{
		if (ft_pointer(ptr / 16, len) == -1)
			return (-1);
	}
	if (ft_putchar(base[ptr % 16], len) == -1)
		return (-1);
	return (0);
}
/*int	main(void)
{
    int		*ptr;
    int		len;
   
    ptr = &len; // Dirección de la variable 'len' como ejemplo
    len = 0;
    printf("El puntero a imprimir es: %p\n", (void *)ptr);
	
    // Imprimir la dirección de memoria usando ft_pointer
    ft_pointer((size_t)ptr, &len);

    // Imprimir el número de caracteres impresos
    printf("\nNúmero de caracteres impresos: %d\n", len);

    return (0);
}*/
