/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:42:51 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 01:40:02 by anpayot          ###   ########.fr       */
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