/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:42:38 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/01 14:43:08 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	min_finder(t_stack *stack)
{
	int	i;
	int	min_idx;
	int	min_val;
	
	if (stack->top == 0)
		return (-1);
	min_val = stack->data[0];
	min_idx = 0;
	i = 1;
	while (i < stack ->top)
	{
		if (stack->date[i] < min_val)
		{
			min_val = stack->data[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

static void	min_to_top(t_stack *stack)
{
	int	min_idx;

	min_idx = min_finder(stack);
	if (min_idx <= stack->top / 2)
	{
		while (min_idx > 0)
		{
			ra_rb(stack, 'a');
			min_idx--;
		}
	}
	else
	{
		while (min_pos < stack->top)
		{
			rra_rrb(stack, 'a');
			min_idx++;
		}
	}
}