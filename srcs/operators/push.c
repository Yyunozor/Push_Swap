/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:20:56 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 00:19:04 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Pushes the top element from one stack to another
 * 
 * This function takes the top element from the source stack and
 * pushes it onto the top of the destination stack. If the source
 * stack is empty, no operation is performed.
 * 
 * @param stack_src Source stack to push from
 * @param stack_dst Destination stack to push to
 * @return int 1 if the push was performed, 0 otherwise
 */
static int	perform_push(t_stack *stack_src, t_stack *stack_dst)
{
	int	top_val;
	int	i;

	if (stack_src->top <= 0)
		return (0);
	top_val = stack_src->data[0];
	i = 0;
	while (i < stack_src->top - 1)
	{
		stack_src->data[i] = stack_src->data[i + 1];
		i++;
	}
	stack_src->top--;
	i = stack_dst->top;
	while (i > 0)
	{
		stack_dst->data[i] = stack_dst->data[i - 1];
		i--;
	}
	stack_dst->data[0] = top_val;
	stack_dst->top++;
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
	if (stack_letter == 'a')
		push(dest, src, 'a');
	else if (stack_letter == 'b')
		push(src, dest, 'b');
}
