/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/04/14 20:36:16 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 17:00:45 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "../ft_printf2/includes/ft_printf.h"
# include "func_comm.h"

# include <limits.h>

// Stack Operations

void	sa_sb(t_stack *stack, char stack_letter);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa_pb(t_stack *stack_src, t_stack *stack_dst, char stack_letter);
void	ra_rb(t_stack *stack, char stack_letter);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra_rrb(t_stack *stack, char stack_letter);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Stack Utilities

t_stack	*stack_init(int capacity);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);



// Parse Arguments

t_stack	*parse_args(int ac, char **av);
int		is_valid_int(char *str);
int		has_duplicates(int *arr, int size);
int		process_space_arg(char *arg, char **result, int index);
int		count_args(int ac, char **av);
void	free_str_array(char **arr);
t_stack	*load_stack(char **args, int total_count);
int		num_checker(int ac, char **av);

// Sorting Algorithms

void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
void	sort_medium(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

// Sorting Utilities

int		*copy_stack(t_stack *stack, int size);
int		min_finder(t_stack *stack);
int		max_finder(t_stack *stack);
void	min_to_top(t_stack *stack, char stack_id);
void	max_to_top(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	move_to_top(t_stack *stack, int pos, char stack_id);
void	bubble_sort_arr(int *arr, int size);

// // Debug Utilities
// int		debug_is_sorted(t_stack *stack);
// t_stack	*create_random_stack(int size, int min, int max);
// void	generate_test_arguments(int size, int min, int max);
// void	visualize_stacks(t_stack *stack_a, t_stack *stack_b);
// void	print_stack(t_stack *stack, char name);

#endif
