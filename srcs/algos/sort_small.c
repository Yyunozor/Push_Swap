/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 14:26:46 by anpayot          ###   ########.fr       */
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
	int	push_counter;

	if (is_sorted(stack_a))
		return ;
	if (stack_a->top <= 3)
	{
		sort_3(stack_a);
		return ;
	}
	
	// Push the 2 smallest elements to B
	push_counter = stack_a->top - 3;
	push_min_elements(stack_a, stack_b, push_counter);
	
	// Sort the remaining 3 elements in A
	sort_3(stack_a);
	
	// Push elements back from B to A (they're already in order)
	while (stack_b->top > 0)
		pa_pb(stack_b, stack_a, 'a');
}
