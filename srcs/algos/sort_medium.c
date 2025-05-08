/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:47:19 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/08 12:34:52 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Processes a chunk of numbers to move from stack A to B
 *
 * This function moves elements from stack_a to stack_b that belong in a specific
 * chunk of the sorted array. It finds each element's position in stack_a and
 * moves it to the top before pushing to stack_b.
 *
 * @param stack_a Source stack
 * @param stack_b Destination stack
 * @param sorted Array of sorted values from the original stack_a
 * @param chunk_info Array containing [chunk_index, chunk_size]
 */
static void	process_chunk(t_stack *stack_a, t_stack *stack_b,
				int *sorted, int chunk_info[2])
{
	int	pos;
	int	j;
	int	i;

	i = chunk_info[0];
	j = 0;
	while (j < chunk_info[1] && stack_a->top > 0)
	{
		pos = -1;
		while (pos == -1 && j < chunk_info[1])
			pos = find_position(stack_a, sorted[i * chunk_info[1] + j++]);
		if (pos != -1)
		{
			move_to_top(stack_a, pos, 'a');
			pa_pb(stack_a, stack_b, 'b');
		}
	}
}

/**
 * @brief Divides and pushes stack A into chunks to stack B
 *
 * This function divides the elements in stack_a into several chunks based on
 * their sorted order and pushes them to stack_b. It processes one chunk at a time,
 * starting from the smallest values.
 *
 * @param stack_a Source stack
 * @param stack_b Destination stack
 * @param sorted Array of sorted values from the original stack_a
 * @param chunks Number of chunks to divide the stack into
 */
static void	push_chunks(t_stack *stack_a, t_stack *stack_b,
				int *sorted, int chunks)
{
	int	size;
	int	chunk_size;
	int	i;
	int	chunk_info[2];

	size = stack_a->top;
	chunk_size = size / chunks;
	i = 0;
	while (i < chunks)
	{
		chunk_info[0] = i;
		chunk_info[1] = chunk_size;
		process_chunk(stack_a, stack_b, sorted, chunk_info);
		i++;
	}
	while (stack_a->top > 0)
		pa_pb(stack_a, stack_b, 'b');
}

/**
 * @brief Pushes elements back from stack B to A in sorted order
 *
 * This function takes elements from stack_b (which were previously sorted into chunks)
 * and pushes them back to stack_a in descending order. It repeatedly finds the maximum
 * value in stack_b, moves it to the top, and pushes it to stack_a.
 *
 * @param stack_a Destination stack
 * @param stack_b Source stack
 */
static void	push_back_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;

	while (stack_b->top > 0)
	{
		max_pos = max_finder(stack_b);
		move_to_top(stack_b, max_pos, 'b');
		pa_pb(stack_b, stack_a, 'a');
	}
}

void	sort_medium(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted;
	int	size;
	int	chunks;

	if (is_sorted(stack_a))
		return ;
	if (stack_a->top <= 5)
	{
		sort_5(stack_a, stack_b);
		return ;
	}
	size = stack_a->top;
	sorted = copy_stack(stack_a, size);
	if (!sorted)
		return ;
	bubble_sort_arr(sorted, size);
	if (size <= 20)
		chunks = 2;
	else if (size <= 50)
		chunks = 4;
	else
		chunks = 8;
	push_chunks(stack_a, stack_b, sorted, chunks);
	push_back_sorted(stack_a, stack_b);
	free(sorted);
}
