/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/30 00:05:17 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/push_swap.h"

/**
 * @file sort_small.c
 * @brief Functions to sort stacks with small number of elements
 */

void	sort_3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (stack->top < 3 || is_sorted(stack))
		return ;
	first = stack->data[0];
	second = stack->data[1];
	third = stack->data[2];
	if (first > second && second > third)
	{
		sa_sb(stack, 'a');
		rra_rrb(stack, 'a');
	}
	else if (first > second && second < third && first > third)
		ra_rb(stack, 'a');
	else if (first < second && second > third && first < third)
		sa_sb(stack, 'a');
	else if (first > second && second < third && first < third)
	{
		sa_sb(stack, 'a');
	}
	else if (first < second && second > third && first > third)
		rra_rrb(stack, 'a');
}

/**
 * @brief Finds the index of the minimum value in a stack
 *
 * @param stack The stack to search
 * @return The index of the minimum value, or -1 if the stack is empty
 */
static int	min_finder(t_stack *stack)
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

/**
 * @brief Pushes the smallest elements from stack_a to stack_b
 *
 * Finds the minimum element in stack_a, rotates it to the top,
 * and pushes it to stack_b. Repeats this process for the specified count.
 *
 * @param stack_a Source stack
 * @param stack_b Destination stack
 * @param push_count Number of elements to push
 */
static void	push_min_elms(t_stack *stack_a, t_stack *stack_b, int push_counter)
{
	int	min_idx;

	while (push_count > 0)
	{
		min_idx = min_finder(stack_a);
		if (min_idx <= stack_a->top / 2)
		{
			while (min_idx > 0)
			{
				ra_rb(stack_a, 'a');
				min_idx--;
			}
		}
		else
		{
			while (min_idx < stack_a->top)
			{
				rra_rrb(stack_a, 'a');
				min_idx++;
			}
		}
		pa_pb(stack_a, stack_b, 'b');
		push_count--;
	}
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	push_counter;

	if (is_sorted(stack_a))
		return ;
	if (stack_a->top <= 3)
	{
		sort_3(stack_a);
		return ;
	}
	push_counter = stack_a->top - 3;
	push_min_elms(stack_a, stack_b, push_counter);
	sort_3(stack_a);
	while (stack_b->top > 0)
		pa_pb(stack_b, stack_a, 'a');
}
