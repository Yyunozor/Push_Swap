/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_visualizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:05:45 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 11:40:19 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/**
 * @brief Prints a visual representation of a stack
 * 
 * @param stack Stack to visualize
 * @param name Name of the stack (A or B)
 */
void	print_stack(t_stack *stack, char name)
{
	int	i;
	int	max_width;
	int	num_len;
	int	spaces;

	if (!stack)
		return ;
	i = 0;
	max_width = 0;
	// Find maximum width needed for numbers
	while (i < stack->top)
	{
		num_len = 0;
		if (stack->data[i] <= 0)
			num_len++;
		if (stack->data[i] == 0)
			num_len = 1;
		else
		{
			int temp = stack->data[i];
			if (temp < 0)
				temp = -temp;
			while (temp > 0)
			{
				temp /= 10;
				num_len++;
			}
		}
		if (num_len > max_width)
			max_width = num_len;
		i++;
	}

	// Print stack header
	printf("\n----- Stack %c -----\n", name);
	if (stack->top == 0)
	{
		printf("[Empty stack]\n");
		return ;
	}

	// Print stack contents
	i = 0;
	while (i < stack->top)
	{
		num_len = 0;
		if (stack->data[i] <= 0)
			num_len++;
		if (stack->data[i] == 0)
			num_len = 1;
		else
		{
			int temp = stack->data[i];
			if (temp < 0)
				temp = -temp;
			while (temp > 0)
			{
				temp /= 10;
				num_len++;
			}
		}
		
		spaces = max_width - num_len;
		printf("[%d] ", i);
		while (spaces-- > 0)
			printf(" ");
		printf("%d", stack->data[i]);
		if (i == 0)
			printf(" <- top");
		printf("\n");
		i++;
	}
	printf("------------------\n");
}

/**
 * @brief Visualizes both stacks side by side
 * 
 * @param stack_a Stack A
 * @param stack_b Stack B
 */
void	visualize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	printf("\n");
}

/**
 * @brief Checks if stack is sorted correctly
 * 
 * @param stack Stack to check
 * @return int 1 if sorted, 0 otherwise
 */
int	debug_is_sorted(t_stack *stack)
{
	int	i;
	int	result;

	if (!stack || stack->top <= 1)
		return (1);
	i = 0;
	result = 1;
	while (i < stack->top - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
		{
			result = 0;
			break ;
		}
		i++;
	}
	printf("Stack is %s\n", result ? "SORTED" : "NOT SORTED");
	return (result);
}