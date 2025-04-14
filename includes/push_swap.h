/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:35:08 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/14 20:41:43 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf2/includes/ft_printf.h"

/* Basic structure definitions */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* Function prototypes */
// Parser functions
int		input_validation(int argc, char **argv);
t_stack	*parse_args(int argc, char **argv);
t_stack	*stack_init(void);

// Stack operations
void	push(t_stack **src, t_stack **dest, char stack_name);
void	swap(t_stack **stack, char stack_name);
void	rotate(t_stack **stack, char stack_name);
void	reverse_rotate(t_stack **stack, char stack_name);

// Utility functions
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

#endif

