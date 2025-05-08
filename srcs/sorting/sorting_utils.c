/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   anpayot          #+#    #+#             */
/*   Updated: 2025/05/09 01:10:08 by anpayot          ###   ########.fr       */
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

void	min_to_top(t_stack *stack, char stack_id)
{
	int	min_pos;

	min_pos = min_finder(stack);
	if (min_pos <= 0)
		return ;
	move_to_top(stack, min_pos, stack_id);
}

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
