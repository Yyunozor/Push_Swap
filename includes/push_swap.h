/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:35:08 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/14 21:21:18 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf2/includes/ft_printf.h"

/* Basic structure definitions */
typedef struct s_stack
{
	int *array;
	int size;
	int capicity;
}	t_stack;

/* Function prototypes */
// Parser functions
int validation(int ac, char **av);
t_stack *parse_args(int ac, char **ac);
t_stack *parse_list(int capacity))

// Stack operations
void	push(t_stack *src

// Utility functions
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

#endif

