/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:50:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/17 02:11:31 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_init(int capacity)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->data = (int *)malloc(sizeof(int) * capacity);
	if (!new_stack->data)
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->top = 0;
	new_stack->capacity = capacity;
	return (new_stack);
}

void	free_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	if ((*stack)->data)
		free((*stack)->data);
	free(*stack);
	*stack = NULL;
}

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->top);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->top <= 1)
		return (1);
	i = 0;
	while (i < stack->top - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
