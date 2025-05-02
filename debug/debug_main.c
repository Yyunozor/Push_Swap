/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:30:17 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 11:40:19 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Tests sort_3 algorithm with a predefined stack
 */
void	test_sort_3(void)
{
	t_stack	*stack;
	int		data[3] = {3, 1, 2}; // Top of stack is 3
	int		i;

	printf("\n--- Testing sort_3 ---\n");
	stack = stack_init(3);
	if (!stack)
		return ;
	i = 0;
	while (i < 3)
	{
		stack->data[i] = data[2 - i]; // Adjust for stack orientation
		i++;
	}
	stack->top = 3;

	printf("Before sorting:\n");
	print_stack(stack, 'A');
	
	sort_3(stack);
	
	printf("\nAfter sorting:\n");
	print_stack(stack, 'A');
	debug_is_sorted(stack);
	
	free_stack(&stack);
}

/**
 * @brief Tests sort_5 algorithm with a predefined stack
 */
void	test_sort_5(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		data[5] = {4, 2, 5, 1, 3}; // Top of stack is 4
	int		i;

	printf("\n--- Testing sort_5 ---\n");
	stack_a = stack_init(5);
	stack_b = stack_init(5);
	if (!stack_a || !stack_b)
	{
		if (stack_a)
			free_stack(&stack_a);
		if (stack_b)
			free_stack(&stack_b);
		return ;
	}
	
	i = 0;
	while (i < 5)
	{
		stack_a->data[i] = data[4 - i]; // Adjust for stack orientation
		i++;
	}
	stack_a->top = 5;

	printf("Before sorting:\n");
	visualize_stacks(stack_a, stack_b);
	
	sort_5(stack_a, stack_b);
	
	printf("\nAfter sorting:\n");
	visualize_stacks(stack_a, stack_b);
	debug_is_sorted(stack_a);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
}

/**
 * @brief Tests sort_medium algorithm with random numbers
 */
void	test_sort_medium(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size = 20;

	printf("\n--- Testing sort_medium with %d elements ---\n", size);
	stack_a = create_random_stack(size, -100, 100);
	if (!stack_a)
		return ;
	
	stack_b = stack_init(size);
	if (!stack_b)
	{
		free_stack(&stack_a);
		return ;
	}

	printf("Before sorting:\n");
	visualize_stacks(stack_a, stack_b);
	
	sort_medium(stack_a, stack_b);
	
	printf("\nAfter sorting:\n");
	visualize_stacks(stack_a, stack_b);
	debug_is_sorted(stack_a);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
}

/**
 * @brief Tests sort_large algorithm with random numbers
 */
void	test_sort_large(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size = 100;

	printf("\n--- Testing sort_large with %d elements ---\n", size);
	stack_a = create_random_stack(size, -500, 500);
	if (!stack_a)
		return ;
	
	stack_b = stack_init(size);
	if (!stack_b)
	{
		free_stack(&stack_a);
		return ;
	}

	printf("Before sorting (showing first/last few elements):\n");
	// Only show first/last few elements to avoid flooding terminal
	printf("Stack A: Top [%d, %d, ..., %d, %d] Bottom\n", 
		stack_a->data[0], stack_a->data[1], 
		stack_a->data[stack_a->top-2], stack_a->data[stack_a->top-1]);
	
	sort_large(stack_a, stack_b);
	
	printf("\nAfter sorting (showing first/last few elements):\n");
	printf("Stack A: Top [%d, %d, ..., %d, %d] Bottom\n", 
		stack_a->data[0], stack_a->data[1], 
		stack_a->data[stack_a->top-2], stack_a->data[stack_a->top-1]);
	debug_is_sorted(stack_a);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
}

/**
 * @brief Generates random test cases
 */
void	generate_tests(void)
{
	printf("\n--- Generating Test Cases ---\n");
	printf("3 random numbers: ");
	generate_test_arguments(3, -10, 10);
	
	printf("5 random numbers: ");
	generate_test_arguments(5, -20, 20);
	
	printf("10 random numbers: ");
	generate_test_arguments(10, -50, 50);
	
	printf("100 random numbers: ");
	generate_test_arguments(100, -500, 500);
}

/**
 * @brief Main function for the debug program
 */
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		// If arguments are provided, test the specific algorithm
		if (strcmp(argv[1], "sort_3") == 0)
			test_sort_3();
		else if (strcmp(argv[1], "sort_5") == 0)
			test_sort_5();
		else if (strcmp(argv[1], "sort_medium") == 0)
			test_sort_medium();
		else if (strcmp(argv[1], "sort_large") == 0)
			test_sort_large();
		else if (strcmp(argv[1], "generate") == 0)
			generate_tests();
		else
			printf("Unknown test: %s\n", argv[1]);
	}
	else
	{
		// Run all tests
		test_sort_3();
		test_sort_5();
		test_sort_medium();
		test_sort_large();
		generate_tests();
	}
	return (0);
}