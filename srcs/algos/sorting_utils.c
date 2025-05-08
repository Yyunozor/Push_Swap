/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:42:38 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/08 12:34:52 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Copies the stack data to a new integer array
 * 
 * This function allocates memory for a new array and copies
 * the data from the stack to this array.
 * 
 * @param stack The stack to copy from
 * @param size The number of elements to copy
 * @return A pointer to the newly allocated array
 */
int	*copy_stack(t_stack *stack, int size)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = stack->data[i];
		i++;
	}
	return (copy);
}

/**
 * @brief Finds the minimum value in a stack
 * 
 * This function iterates through the stack to find the
 * position of the minimum value.
 * 
 * @param stack The stack to search
 * @return The position of the minimum value
 */
int	min_finder(t_stack *stack)
{
	int	i;
	int	min;
	int	min_pos;

	if (stack->top <= 0)
		return (-1);
	min = stack->data[0];
	min_pos = 0;
	i = 1;
	while (i < stack->top)
	{
		if (stack->data[i] < min)
		{
			min = stack->data[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

/**
 * @brief Finds the maximum value in a stack
 * 
 * This function iterates through the stack to find the
 * position of the maximum value.
 * 
 * @param stack The stack to search
 * @return The position of the maximum value
 */
int	max_finder(t_stack *stack)
{
	int	i;
	int	max;
	int	max_pos;

	if (stack->top <= 0)
		return (-1);
	max = stack->data[0];
	max_pos = 0;
	i = 1;
	while (i < stack->top)
	{
		if (stack->data[i] > max)
		{
			max = stack->data[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

/**
 * @brief Moves the minimum value to the top of the stack
 * 
 * This function finds the minimum value in the stack and
 * performs rotation operations to bring it to the top position.
 * 
 * @param stack The stack to manipulate
 * @param stack_id Identifier for the stack ('a' or 'b')
 */
void	min_to_top(t_stack *stack, char stack_id)
{
	int	min_pos;

	min_pos = min_finder(stack);
	if (min_pos <= 0)
		return ;
	move_to_top(stack, min_pos, stack_id);
}

/**
 * @brief Moves the maximum value to the top of the stack
 * 
 * This function finds the maximum value in the stack and
 * performs rotation operations to bring it to the top position.
 * 
 * @param stack The stack to manipulate
 */
void	max_to_top(t_stack *stack)
{
	int	max_pos;

	max_pos = max_finder(stack);
	if (max_pos <= 0)
		return ;
	if (max_pos <= stack->top / 2)
	{
		while (max_pos > 0)
		{
			ra_rb(stack, 'b');
			max_pos--;
		}
	}
	else
	{
		while (max_pos < stack->top)
		{
			rra_rrb(stack, 'b');
			max_pos++;
		}
	}
}
