/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/29 22:49:43 by anpayot          ###   ########.fr       */
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
