/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/08 12:34:52 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Normalizes the stack values to their position in sorted order
 *
 * This function replaces each value in the stack with its index in the sorted array.
 * For example, the smallest number becomes 0, the second smallest becomes 1, etc.
 * This normalization simplifies the radix sort process by working with sequential
 * indices instead of potentially large or negative numbers.
 *
 * @param stack The stack to normalize
 * @param size The size of the stack
 */
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

/**
 * @brief Counts the number of bits needed to represent a given number
 *
 * This function determines how many binary digits are needed to represent
 * the given number, which is essential for determining how many passes
 * the radix sort algorithm needs to make.
 *
 * @param max The maximum value to represent
 * @return The number of bits required
 */
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

/**
 * @brief Performs radix sort on the stack using bit operations
 *
 * This function implements the radix sort algorithm by examining each bit position
 * (from least significant to most significant) for each number. Numbers with a 0 in
 * the current bit position are pushed to stack B, and then all numbers are pushed
 * back to stack A before moving to the next bit position.
 *
 * @param stack_a The main stack to sort
 * @param stack_b The helper stack
 * @param size The size of the stack
 * @param bits The number of bits to process
 */
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

