/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:03 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 05:05:54 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Performs a reverse rotation (downwards) on a stack
 * 
 * This function moves the last element of a stack to the beginning.
 * If the stack has less than 2 elements, nothing happens.
 * 
 * @param stack The stack to manipulate
 * @return int 1 if the reverse rotation was performed, 0 otherwise
 */
static int	perform_rev_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top <= 1)
		return (0);
	temp = stack->data[stack->top - 1];
	i = stack->top - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = temp;
	return (1);
}

/**
 * @brief Unified function for all reverse rotation operations
 * 
 * This function handles reverse rotation operations (rra, rrb, rrr)
 * based on the op parameter passed.
 * 
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param op Operation code: 'a' for rra, 'b' for rrb, 'r' for rrr
 */
static void	rev_rotate(t_stack *stack_a, t_stack *stack_b, char op)
{
	int	rotated;

	rotated = 0;
	if (op == 'a' || op == 'r')
		rotated += perform_rev_rotate(stack_a);
	if (op == 'b' || op == 'r')
		rotated += perform_rev_rotate(stack_b);
	
	if (rotated)
	{
		if (op == 'a')
			ft_printf("rra\n");
		else if (op == 'b')
			ft_printf("rrb\n");
		else if (op == 'r')
			ft_printf("rrr\n");
	}
}

void	rra_rrb(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
		rev_rotate(stack, NULL, 'a');
	else if (stack_letter == 'b')
		rev_rotate(NULL, stack, 'b');
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a, stack_b, 'r');
}
