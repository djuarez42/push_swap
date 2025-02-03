/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:39:38 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 17:22:33 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (args == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		(*len) += 6;
		return (0);
	}
	while (args[i] != '\0')
	{
		if (ft_putchar(args[i], len) == -1)
			return (-1);
		i++;
	}
	return (0);
}
/*int     main(void)
{
        int     len;
        char    *message;

        len = 0;
        message = " Hola me llamo cristhian";
        printf(" El string resultante es: \n");
                ft_test_putstr(message, &len);
        printf( " El total de caracteres impresos es de : '%d'\n", len);
        return (0);
}*/
