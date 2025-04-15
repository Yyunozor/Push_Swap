/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:40:43 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/15 22:44:53 by anpayot          ###   ########.fr       */
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

/**
 * @brief Initializes a new stack with the specified capacity
 *
 * @param capacity Maximum number of elements the stack can hold
 * @return Pointer to the newly created stack or NULL if allocation fails
 * 
 * @details
 * Creates and allocates memory for a new stack structure with the specified
 * maximum capacity.
 * - Allocates memory for the stack structure
 * - Allocates memory for the stack's internal array of integers
 * - Initializes size to 0 and sets the maximum capacity
 * - Returns NULL if any memory allocation fails
 * 
 * @note Time complexity: O(1)
 * @note Space complexity: O(capacity)
 */
t_stack	*stack_init(int capacity);