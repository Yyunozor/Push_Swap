/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:20:56 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 05:07:34 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Pushes the first element of one stack to another stack
 * 
 * This function takes the first element of the source stack and places it
 * at the top of the destination stack. If the source stack is empty,
 * nothing happens.
 * 
 * @param src Source stack
 * @param dest Destination stack
 * @return int 1 if the push was performed, 0 otherwise
 */
static int	perform_push(t_stack *src, t_stack *dest)
{
	int	i;

	if (src->top == 0)
		return (0);
	i = dest->top;
	while (i > 0)
	{
		dest->data[i] = dest->data[i - 1];
		i--;
	}
	dest->data[0] = src->data[0];
	dest->top++;
	i = 0;
	while (i < src->top - 1)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->top--;
	return (1);
}

/**
 * @brief Unified function for all push operations
 * 
 * This function handles push operations (pa, pb)
 * based on the op parameter passed.
 * 
 * @param src_a Source stack A
 * @param src_b Source stack B
 * @param op Operation code: 'a' for pa (B->A), 'b' for pb (A->B)
 */
static void	push(t_stack *src_a, t_stack *src_b, char op)
{
	int	pushed;

	pushed = 0;
	if (op == 'a')
		pushed = perform_push(src_b, src_a);
	else if (op == 'b')
		pushed = perform_push(src_a, src_b);
	
	if (pushed)
	{
		if (op == 'a')
			ft_printf("pa\n");
		else if (op == 'b')
			ft_printf("pb\n");
	}
}

void	pa_pb(t_stack *src, t_stack *dest, char stack_letter)
{
	if (stack_letter== 'a')
		push(dest, src, 'a');
	else if (stack_letter == 'b')
		push(src, dest, 'b');
}