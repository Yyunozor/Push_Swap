/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:12:01 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/17 02:13:34 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Prints the content of a stack
 * 
 * Utility function for debugging purposes.
 * 
 * @param stack The stack to print
 */
void	print_stack(t_stack *stack)
{
	int	i;

	if (!stack)
	{
		ft_printf("Stack is NULL\n");
		return ;
	}
	if (stack->top == 0)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	ft_printf("Stack contents (top to bottom):\n");
	i = 0;
	while (i < stack->top)
	{
		ft_printf("[%d]: %d\n", i, stack->data[i]);
		i++;
	}
}
