/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 07:53:44 by djuarez           #+#    #+#             */
/*   Updated: 2025/01/20 07:56:04 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int	count;
	bool	inside_word;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		inside_word = false;
		while (str[i] == separator && str[i])
			++i;
		while (str[i] != separator && str[i])
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			i++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor;
	char	*next_str;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	if (len == 0)
		return (NULL);
	next_str =  malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int	words_number;
	char	**vector_strings;
	int	i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit (1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
		if (NULL == vector_strings)
			return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}	
	vector_strings[i] = NULL;
	return (vector_strings);
}

int     main()
{
    char	*message;
    char	**result;
    int		i;

    i = 0;
    message = "hola me llamo cristhian";
    result = ft_split(message, ' ');

    while (result[i])
    {
	    ft_printf("palabra[%d] -> %s\n",i, result[i]);
	    free (result[i]);
	    i++;
    }
    free(result);
    return (0);
}

