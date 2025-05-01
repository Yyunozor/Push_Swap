/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/01 14:43:04 by anpayot          ###   ########.fr       */
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
	else if (first < second && second > third && first < third)
		sa_sb(stack, 'a');
	else if (first < second && second < third && first < third)
	{
		sa_sb(stack, 'a');
		ra_rb(stack, 'a');
	}
	else if (first < second && second > third)
		rra_rrb(stack, 'a');
}

void	sort_5(t_stack *stack_a, t_stack stack b)
{
	int	min_idx;
	int	push_counter;

	if (is_sorted(stack_a))
		return ;
	if (stack_a->top <= 3)
	{
		sort_3(stack_a);
		return ;
	}
	push_counter = stack_a->top - 3;
	while (push_counter > 0)
	{
		min_idx = min_finder;
		if(min_idx <= stack_a-> top / 2)
			while (min_idx-- > 0)
				ra_rb(stack_a, 'a');
		else
			while (min_idx++ < stack_a->top)
				rra_rrb(stack, 'a');
		pa_pb(stack_a, stack_b, 'b');
		push_counter--;
	}
	sort_3(stack_a);
	while (stack_b->top > 0)
		pa_pb(stack_b, stack_a, 'a');
}
