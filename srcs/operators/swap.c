/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:20:16 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/08 12:34:52 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Swaps the first two elements of a stack
 * 
 * This function swaps the first two elements at the top of the stack.
 * If the stack has fewer than 2 elements, no operation is performed.
 * 
 * @param stack The stack to perform the swap on
 * @return int 1 if the swap was performed, 0 otherwise
 */
static int	perform_swap(t_stack *stack)
{
	int	temp;

	if (stack->top <= 1)
		return (0);
	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
	return (1);
}

/**
 * @brief Unified function for all swap operations
 * 
 * This function handles swap operations (sa, sb, ss)
 * based on the op parameter passed.
 * 
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param op Operation code: 'a' for sa, 'b' for sb, 's' for ss
 */
static void	swap(t_stack *stack_a, t_stack *stack_b, char op)
{
	int	swapped;

	swapped = 0;
	if (op == 'a' || op == 's')
		swapped += perform_swap(stack_a);
	if (op == 'b' || op == 's')
		swapped += perform_swap(stack_b);
	if (swapped)
	{
		if (op == 'a')
			ft_printf("sa\n");
		else if (op == 'b')
			ft_printf("sb\n");
		else if (op == 's')
			ft_printf("ss\n");
	}
}

void	sa_sb(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
		swap(stack, NULL, 'a');
	else if (stack_letter == 'b')
		swap(NULL, stack, 'b');
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, stack_b, 's');
}
