/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 11:31:50 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	normalize_stack(t_stack *stack, int size)
{
	int	*copy;
	int	*sorted;
	int	i;
	int	j;

	copy = copy_stack(stack, size);
	sorted = copy_stack(stack, size);
	if (!copy || !sorted)
	{
		free(copy);
		free(sorted);
		return ;
	}
	bubble_sort_arr(sorted, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (copy[i] == sorted[j])
			{
				stack->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
	free(sorted);
}

static int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

static void	radix_sort_bits(t_stack *stack_a, t_stack *stack_b, int size, int bits)
{
	int	i;
	int	j;

	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->data[0] >> i) & 1) == 0)
				pa_pb(stack_a, stack_b, 'b');
			else
				ra_rb(stack_a, 'a');
			j++;
		}
		while (stack_b->top > 0)
			pa_pb(stack_b, stack_a, 'a');
		i++;
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max;
	int	max_bits;

	if (is_sorted(stack_a))
		return ;
	if (stack_a->top <= 100)
	{
		sort_medium(stack_a, stack_b);
		return ;
	}
	size = stack_a->top;
	normalize_stack(stack_a, size);
	max = size - 1;
	max_bits = count_bits(max);
	radix_sort_bits(stack_a, stack_b, size, max_bits);
}

