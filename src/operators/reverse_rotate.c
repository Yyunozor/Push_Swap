/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:21:03 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 01:15:59 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack *stack, char stack_name)
{
	int	temp;
	int	i;

	if (stack->size <= 1)
		return ;
	temp = stack->array[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = temp;
	
	if (stack_name == 'a')
		ft_printf("rra\n");
	else if (stack_name == 'b')
		ft_printf("rrb\n");
	else if (stack_name == 'r')
		ft_printf("rrr\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_printf("rrr\n");
}
