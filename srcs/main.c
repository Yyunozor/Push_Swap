/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:01:12 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/02 14:26:46 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Frees memory and handles exit
 * 
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param exit_code Exit code
 * @return int Exit code
 */
static int	clean_exit(t_stack *stack_a, t_stack *stack_b, int exit_code)
{
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	return (exit_code);
}

/**
 * @brief Selects the appropriate sorting algorithm based on stack size
 * 
 * @param stack_a Stack to sort
 * @param stack_b Helper stack
 */
static void	select_sort_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->top;
	if (size <= 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_5(stack_a, stack_b);
	else if (size <= 100)
		sort_medium(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}

// Debug function to print the stack contents
static void print_debug_stack(t_stack *stack, char *name)
{
    int i;
    
    ft_printf("Stack %s contents (top to bottom): ", name);
    i = 0;
    while (i < stack->top)
    {
        ft_printf("%d ", stack->data[i]);
        i++;
    }
    ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	
	// DEBUG: Print stack contents after initialization
	print_debug_stack(stack_a, "A");
	
	if (is_sorted(stack_a))
		return (clean_exit(stack_a, NULL, 0));
	stack_b = stack_init(stack_a->capacity);
	if (!stack_b)
	{
		ft_printf("Error\n");
		return (clean_exit(stack_a, NULL, 1));
	}
	select_sort_algorithm(stack_a, stack_b);
	
	// DEBUG: Print stack contents after sorting
	print_debug_stack(stack_a, "A (after sorting)");
	
	return (clean_exit(stack_a, stack_b, 0));
}


