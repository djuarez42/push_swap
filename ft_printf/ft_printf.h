/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:19:56 by djuarez           #+#    #+#             */
/*   Updated: 2024/08/07 20:01:02 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int			ft_putchar(char ch, int *len);
int			ft_putstr(char *args, int *len);
int			ft_check_conv(char c, va_list *args, int *len, int *i);
int			ft_putnbr(int nbr, int *len);
int			ft_hexadecimal(unsigned int x, int *len, char x_or_x);
int			ft_unsigned_int(unsigned int u, int *len);
int			ft_pointer(size_t ptr, int *len);
int			ft_printf(const char *str, ...);

#endif
