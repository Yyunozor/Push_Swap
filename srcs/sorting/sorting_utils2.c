/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:42:51 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 01:10:08 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Finds the position of a value in the stack
 * 
 * This function searches through the stack to find the position
 * of a specific value. Returns -1 if the value is not found.
 * 
 * @param stack The stack to search in
 * @param value The value to find
 * @return The position of the value, or -1 if not found
 */
int	find_position(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->data[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Moves an element at a specific position to the top of the stack
 * 
 * This function performs rotation or reverse rotation operations to bring
 * an element at a specific position to the top of the stack using the most
 * efficient sequence of operations.
 * 
 * @param stack The stack to manipulate
 * @param pos The position of the element to move
 * @param stack_id Identifier for the stack ('a' or 'b')
 */
void	move_to_top(t_stack *stack, int pos, char stack_id)
{
	if (pos <= 0)
		return ;
	if (pos <= stack->top / 2)
	{
		while (pos > 0)
		{
			ra_rb(stack, stack_id);
			pos--;
		}
	}
	else
	{
		while (pos < stack->top)
		{
			rra_rrb(stack, stack_id);
			pos++;
		}
	}
}

/**
 * @brief Performs bubble sort on an integer array
 * 
 * This function sorts an array of integers using the bubble sort algorithm.
 * The result is arranged in ascending order.
 * 
 * @param arr The array to sort
 * @param size The size of the array
 */
void	bubble_sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}