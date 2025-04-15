/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:20:56 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 01:04:35 by anpayot          ###   ########.fr       */
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