/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 07:52:52 by djuarez           #+#    #+#             */
/*   Updated: 2025/01/23 09:52:29 by djuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//*** Handle errors/free ***

void		free_matrix(char **argv);
void		free_stack(t_stack_node **stack);
void		error_free(t_stack_node **a, char **argv, bool flag_argc_2);
int		error_syntax(char *str_nbr);
int		error_repetition(t_stack_node *a, int nbr);

//*** linked list utils ***
t_stack_node    *find_last_node(t_stack_node *head);
void    append_node(t_stack_node **stack, int nbr);
t_stack_node    *find_smallest(t_stack_node *stack);
t_stack_node    *return_cheapest(t_stack_node *stack);
int     stack_len(t_stack_node *stack);





#endif
