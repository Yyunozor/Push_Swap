/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:36:55 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 11:31:50 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	move_to_top(t_stack *stack, int pos, char stack_id)
{
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

void	max_to_top(t_stack *stack)
{
	int	max_idx;

	max_idx = max_finder(stack);
	if (max_idx <= stack->top / 2)
	{
		while (max_idx > 0)
		{
			ra_rb(stack, 'b');
			max_idx--;
		}
	}
	else
	{
		while (max_idx < stack->top)
		{
			rra_rrb(stack, 'b');
			max_idx++;
		}
	}
}

void	bubble_sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
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