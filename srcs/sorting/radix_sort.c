/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 01:18:24 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Counts the number of bits needed to represent a number
 *
 * @param num The number to analyze
 * @return int The number of bits required
 */
int	count_bits(int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		count++;
		num >>= 1;
	}
	return (count);
}

/**
 * @brief Helper function to perform the first part of radix sort
 *
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param bit Current bit position being processed
 * @param size Number of elements to process
 */
static void	radix_process_bit(t_stack *stack_a, t_stack *stack_b,
							int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((stack_a->data[0] >> bit) & 1) == 0)
			pa_pb(stack_a, stack_b, 'b');
		else
			ra_rb(stack_a, 'a');
		j++;
	}
}

/**
 * @brief Performs a binary radix sort on the stack
 *
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param size Number of elements to sort
 * @param max_bits Maximum number of bits to process
 */
void	radix_sort_bits(t_stack *stack_a, t_stack *stack_b,
						int size, int max_bits)
{
	int	i;

	i = 0;
	while (i < max_bits)
	{
		radix_process_bit(stack_a, stack_b, i, size);
		while (stack_b->top > 0)
			pa_pb(stack_b, stack_a, 'a');
		i++;
	}
}