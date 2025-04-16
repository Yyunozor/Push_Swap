/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:06 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 02:51:12 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Rotates a stack upwards
 * 
 * This function moves the first element of a stack to the end.
 * If the stack has less than 2 elements, nothing happens.
 * 
 * @param stack The stack to manipulate
 * @return int 1 if the rotation was performed, 0 otherwise
 */
static int perform_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top <= 1)
		return (0);
	temp = stack->data[0];
	i = 0;
	while (i < stack->top - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top - 1] = temp;
	return (1);
}

/**
 * @brief Unified function for all rotation operations
 * 
 * This function handles rotation operations (ra, rb, rr)
 * based on the op parameter passed.
 * 
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param op Operation code: 'a' for ra, 'b' for rb, 'r' for rr
 */
static void rotate(t_stack *stack_a, t_stack *stack_b, char op)
{
	int	rotated;

	rotated = 0;
	if (op == 'a' || op == 'r')
		rotated += perform_rotate(stack_a);
	if (op == 'b' || op == 'r')
		rotated += perform_rotate(stack_b);
	
	if (rotated)
	{
		if (op == 'a')
			ft_printf("ra\n");
		else if (op == 'b')
			ft_printf("rb\n");
		else if (op == 'r')
			ft_printf("rr\n");
	}
}

void ra_rb(t_stack *stack, char stack_name)
{
	if (stack_name == 'a')
		rotate(stack, NULL, 'a');
	else if (stack_name == 'b')
		rotate(NULL, stack, 'b');
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, stack_b, 'r');
}
