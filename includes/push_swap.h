/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:35:08 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 01:06:08 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf2/includes/ft_printf.h"
# include "push_swap_doc.h"

/* Basic structure definitions */
typedef struct s_stack
{
	int *array;
	int size;
	int capacity;
}	t_stack;

/* Function prototypes */
// Parser functions
int 	validation(int ac, char **av);
t_stack *parse_args(int ac, char **av);
t_stack *stack_init(int capacity);

// Stack operations
void	push(t_stack *src, t_stack *dest, char stack_name);		// pa, pb
void	swap(t_stack *stack, char stack_name);					// sa, sb, ss
void	rotate(t_stack *stack, char stack_name_);				// ra, rb, rr	
void	reverse_rotate(t_stack *stack, char stack_name);		// rra, rrb, rrr

// Utility functions
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
void	print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

// Sorting algos
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
void	sort_medium(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

#endif

