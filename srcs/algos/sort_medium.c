/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:19 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/01 14:49:22 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	bubble_sort_arr(int *arr, int size)
{
	int	i;
	int j;
	int temp;

	i = 0;
	while(i < size)
	{
		j = 0;
		while (j < size -1 - i)
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

static int	find_position(t_stack *stack, int value)
{
	int	i;
	
	i = 0;
	while(i < stack-> top)
	{
		if (stack->data[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->top / 2)
	{
		while (pos > 0)
		{
			ra_rb(stack, 'a');
			pos--;
		}
	}
	else
	{
		while (pos < stack->top)
		{
			rra_rrb(stack, 'a');
			pos++;
		}
	}
}
