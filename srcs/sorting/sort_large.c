/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+    */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/05/01 16:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 01:10:08 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Prepares and allocates memory for stack normalization
 *
 * @param stack The stack to normalize
 * @param size The size of the stack
 * @return int** Array of pointers to copy and sorted arrays, or NULL if failed
 */
static int	**prepare_normalization(t_stack *stack, int size)
{
	int	**arrays;
	int	*copy;
	int	*sorted;

	arrays = (int **)malloc(sizeof(int *) * 2);
	if (!arrays)
		return (NULL);
	copy = copy_stack(stack, size);
	sorted = copy_stack(stack, size);
	if (!copy || !sorted)
	{
		free(copy);
		free(sorted);
		free(arrays);
		return (NULL);
	}
	bubble_sort_arr(sorted, size);
	arrays[0] = copy;
	arrays[1] = sorted;
	return (arrays);
}

/**
 * @brief Maps a value to its position in the sorted array
 *
 * @param stack Stack to update
 * @param i Current position in the stack
 * @param copy Original stack values
 * @param sorted Sorted array of values
 */
static void	map_value_to_index(t_stack *stack, int i, int *copy, int *sorted)
{
	int	j;
	int	size;

	size = stack->top;
	j = -1;
	while (++j < size)
	{
		if (copy[i] == sorted[j])
		{
			stack->data[i] = j;
			break ;
		}
	}
}

/**
 * @brief Normalizes the stack values to indices in sorted order
 *
 * Replaces each value with its position in the sorted array.
 * The smallest number becomes 0, second smallest becomes 1, etc.
 */
static void	normalize_stack(t_stack *stack, int size)
{
	int	**arrays;
	int	*copy;
	int	*sorted;
	int	i;

	arrays = prepare_normalization(stack, size);
	if (!arrays)
		return ;
	copy = arrays[0];
	sorted = arrays[1];
	i = -1;
	while (++i < size)
		map_value_to_index(stack, i, copy, sorted);
	free(copy);
	free(sorted);
	free(arrays);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max;
	int	max_bits;

	if (is_sorted(stack_a))
		return ;
	size = stack_a->top;
	normalize_stack(stack_a, size);
	max = size - 1;
	max_bits = count_bits(max);
	radix_sort_bits(stack_a, stack_b, size, max_bits);
}

