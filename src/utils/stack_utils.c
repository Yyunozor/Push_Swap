/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:50:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 02:51:12 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Frees the memory allocated to a stack
 *
 * This function properly deallocates all memory associated with a stack,
 * including the integer array and the stack structure itself.
 * 
 * @param stack Pointer to the stack pointer to be freed
 */
void	free_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	if ((*stack)->data)
		free((*stack)->data);
	free(*stack);
	*stack = NULL;
}

/**
 * @brief Prints the content of a stack
 *
 * This function displays all elements in a stack from top to bottom.
 * Useful for debugging and visualization.
 * 
 * @param stack The stack to print
 */
void	print_stack(t_stack *stack)
{
	int	i;

	if (!stack)
	{
		ft_printf("Stack is NULL\n");
		return ;
	}
	if (stack->top == 0)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	ft_printf("Stack contents (top to bottom):\n");
	i = 0;
	while (i < stack->top)
	{
		ft_printf("[%d]: %d\n", i, stack->data[i]);
		i++;
	}
}

/**
 * @brief Returns the number of elements in a stack
 *
 * @param stack The stack to check
 * @return The number of elements in the stack
 */
int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->top);
}

/**
 * @brief Checks if a stack is sorted in ascending order
 *
 * @param stack The stack to check
 * @return 1 if the stack is sorted, 0 otherwise
 */
int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->top <= 1)
		return (1);
	i = 0;
	while (i < stack->top - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}