/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:42:38 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 14:26:46 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	min_finder(t_stack *stack)
{
	int	i;
	int	min_idx;
	int	min_val;

	if (stack->top == 0)
		return (-1);
	min_val = stack->data[0];
	min_idx = 0;
	i = 1;
	while (i < stack->top)
	{
		if (stack->data[i] < min_val)
		{
			min_val = stack->data[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	max_finder(t_stack *stack)
{
	int	i;
	int	max_idx;
	int	max_val;

	if (stack->top == 0)
		return (-1);
	max_val = stack->data[0];
	max_idx = 0;
	i = 1;
	while (i < stack->top)
	{
		if (stack->data[i] > max_val)
		{
			max_val = stack->data[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

void	min_to_top(t_stack *stack, char stack_id)
{
	int	min_idx;

	min_idx = min_finder(stack);
	if (min_idx <= stack->top / 2)
	{
		while (min_idx > 0)
		{
			ra_rb(stack, stack_id);
			min_idx--;
		}
	}
	else
	{
		while (min_idx < stack->top)
		{
			rra_rrb(stack, stack_id);
			min_idx++;
		}
	}
}
