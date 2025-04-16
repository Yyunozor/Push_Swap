/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:06 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 02:04:07 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_internal(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size <= 1)
		return ;
	temp = stack->array[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->size - 1] = temp;
}

void	ra_rb(t_stack *stack, char stack_name)
{
	if (stack->size <= 1)
		return ;
	rotate_internal(stack);
	if (stack_name == 'a')
		ft_printf("ra\n");
	else if (stack_name == 'b')
		ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 && stack_b->size <= 1)
		return ;
	rotate_internal(stack_a);
	rotate_internal(stack_b);
	ft_printf("rr\n");
}
