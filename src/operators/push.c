/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:20:56 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/15 22:30:47 by anpayot          ###   ########.fr       */
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

/*
push function explanation:

Purpose:
- Moves the top element from the source stack to the top of the destination stack
- Implements the 'pa' and 'pb' operations required by push_swap

Parameters:
- src: The source stack to take the element from
- dest: The destination stack to place the element on top of
- stack_name: 'a' or 'b' to determine which operation to print

Implementation details:
1. First checks if source stack is empty - if so, does nothing
2. Makes space at the top of destination stack by shifting all elements down
3. Takes the top element from source and places it at the top of destination
4. Updates the destination size to include the new element
5. Shifts all elements in source up to remove the top element
6. Updates the source size to reflect the removed element
7. Prints the appropriate operation ('pa' or 'pb')

Time complexity: O(n) where n is the larger of the source or destination sizes
Space complexity: O(1) - only uses a single counter variable
*/
void	push(t_stack *src, t_stack *dest, char stack_name);