/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/08 12:34:52 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	else if (first > second && second < third)
		sa_sb(stack, 'a');
	else if (first < second && second > third && first < third)
	{
		sa_sb(stack, 'a');
		ra_rb(stack, 'a');
	}
	else if (first < second && second > third)
		rra_rrb(stack, 'a');
}

/**
 * @brief Pushes minimum elements from stack A to stack B
 * 
 * This function finds the smallest element in stack_a and moves it to the top,
 * then pushes it to stack_b. It repeats this process for the specified number
 * of elements.
 * 
 * @param stack_a Source stack
 * @param stack_b Destination stack
 * @param count Number of minimum elements to push
 */
static void	push_min_elements(t_stack *stack_a, t_stack *stack_b, int count)
{
	while (count > 0)
	{
		// Find the smallest element and move to top of A
		min_to_top(stack_a, 'a');
		// Push to B
		pa_pb(stack_a, stack_b, 'b');
		count--;
	}
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->top;
	if (size <= 1 || is_sorted(stack_a))
		return ;
	else if (size == 2)
	{
		if (stack_a->data[0] > stack_a->data[1])
			sa_sb(stack_a, 'a');
		return ;
	}
	else if (size == 3)
	{
		sort_3(stack_a);
		return ;
	}
	// For size 4 or 5, push min elements to B
	push_min_elements(stack_a, stack_b, size - 3);
	// Sort the remaining 3 elements in A
	sort_3(stack_a);
	// Push all elements back from B to A
	while (stack_b->top > 0)
		pa_pb(stack_b, stack_a, 'a');
}
