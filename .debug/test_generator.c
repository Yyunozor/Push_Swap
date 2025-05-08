/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:18:28 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 11:35:59 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Checks if a number is already in an array
 * 
 * @param arr Array to check
 * @param size Size of the array
 * @param num Number to look for
 * @return int 1 if found, 0 otherwise
 */
static int	is_in_array(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Generates an array of unique random numbers
 * 
 * @param size Size of the array to generate
 * @param min Minimum value
 * @param max Maximum value
 * @return int* Array of unique random numbers
 */
int	*generate_random_array(int size, int min, int max)
{
	int	*arr;
	int	i;
	int	range;
	int	num;

	if (size <= 0 || min >= max || (max - min + 1) < size)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	range = max - min + 1;
	srand(time(NULL));
	i = 0;
	while (i < size)
	{
		num = min + (rand() % range);
		if (!is_in_array(arr, i, num))
		{
			arr[i] = num;
			i++;
		}
	}
	return (arr);
}

/**
 * @brief Creates a stack with random values
 * 
 * @param size Size of the stack
 * @param min Minimum value
 * @param max Maximum value
 * @return t_stack* Stack with random values
 */
t_stack	*create_random_stack(int size, int min, int max)
{
	t_stack	*stack;
	int		*arr;
	int		i;

	arr = generate_random_array(size, min, max);
	if (!arr)
		return (NULL);
	stack = stack_init(size);
	if (!stack)
	{
		free(arr);
		return (NULL);
	}
	i = size - 1;
	while (i >= 0)
	{
		stack->data[stack->top++] = arr[i];
		i--;
	}
	free(arr);
	return (stack);
}

/**
 * @brief Prints the array as a series of command-line arguments
 * 
 * @param arr Array to print
 * @param size Size of the array
 */
void	print_as_arguments(int *arr, int size)
{
	int	i;

	printf("./push_swap ");
	i = 0;
	while (i < size)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

/**
 * @brief Generates test arguments and prints them
 * 
 * @param size Number of arguments to generate
 * @param min Minimum value
 * @param max Maximum value
 */
void	generate_test_arguments(int size, int min, int max)
{
	int	*arr;

	arr = generate_random_array(size, min, max);
	if (!arr)
	{
		printf("Failed to generate test arguments\n");
		return ;
	}
	print_as_arguments(arr, size);
	free(arr);
}