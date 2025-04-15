/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:20:56 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/15 22:51:00 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *src, t_stack *dest, char stack_name)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dest->size;
	while (i > 0)
	{
		dest->array[i] = dest->array[i - 1];
		i--;
	}
	dest->array[0] = src->array[0];
	dest->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->array[i] = src->array[i + 1];
		i++;
	}
	src->size--;
	if (stack_name == 'a')
		ft_printf("pa\n");
	else if (stack_name == 'b')
		ft_printf("pb\n");
}

/**
 * @brief Moves the top element from source stack to destination stack
 *
 * Implements the 'pa' and 'pb' operations required by push_swap algorithm.
 * When stack_name is 'a', implements 'pa' (push to stack a).
 * When stack_name is 'b', implements 'pb' (push to stack b).
 *
 * @param src The source stack to take the element from
 * @param dest The destination stack to place the element on top of
 * @param stack_name Character 'a' or 'b' to determine which operation to print
 * 
 * @note If the source stack is empty, the function does nothing.
 * 
 * @details Implementation:
 *   1. Checks if source stack is empty
 *   2. Shifts destination stack elements to make space
 *   3. Moves top element from source to destination
 *   4. Updates stack sizes accordingly
 *   5. Prints the operation ('pa' or 'pb')
 *
 * @complexity Time: O(n) where n is the max size of source or destination
 * @complexity Space: O(1)
 */
void	push(t_stack *src, t_stack *dest, char stack_name);