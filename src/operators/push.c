/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:20:56 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/14 20:47:09 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * Pushes the top element from one stack to another
 * src: source stack
 * dest: destination stack
 * stack_name: 'a' or 'b' to print the operation (pa/pb)
 */
void	push(t_stack **src, t_stack **dest, char stack_name)
{
	t_stack	*temp;

	if (!*src)
		return ;
	
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	
	ft_printf("p%c\n", stack_name);
}

