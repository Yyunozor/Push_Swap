/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/04/14 18:35:08 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/19 15:51:30 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "../ft_printf2/includes/ft_printf.h"
# include "push_swap_doc.h"

# include <limits.h>

/* Function prototypes */

// Parser functions
int		num_checker(int ac, char **av);
t_stack	*parse_args(int ac, char **av);
int		count_args(int ac, char **av);
void	free_string_array(char **arr);
int		process_split_arg(char *arg, char **args, int pos);
char	**init_args_array(int count);
int		process_args(int ac, char **av, char **args);

// Stack operations
void	pa_pb(t_stack *src, t_stack *dest, char stack_name);	// pa, pb
void	sa_sb(t_stack *stack, char stack_name);					// sa, sb
void	ss(t_stack *stack_a, t_stack *stack_b);					// ss
void	ra_rb(t_stack *stack, char stack_name);					// ra, rb
void	rra_rrb(t_stack *stack, char stack_name);				// rra, rrb
void	rr(t_stack *stack_a, t_stack *stack_b);					// rr
void	rrr(t_stack *stack_a, t_stack *stack_b);				// rrr

// Utility functions
t_stack	*stack_init(int capacity);
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
