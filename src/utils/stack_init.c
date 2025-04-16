/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:40:43 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 02:51:12 by anpayot          ###   ########.fr       */
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