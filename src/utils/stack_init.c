/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:40:43 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/15 21:23:45 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_init(int capacity)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->array = (int *)malloc(sizeof(int) * capacity);
	if (!new_stack->array)
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->size = 0;
	new_stack->capacity = capacity;
	return (new_stack);
}
