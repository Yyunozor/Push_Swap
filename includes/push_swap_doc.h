/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_doc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:00:00 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/19 18:40:41 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DOC_H
# define PUSH_SWAP_DOC_H

# include "push_swap.h"

/**
 * @file push_swap_doc.h
 * @brief Documentation-only header file for Push_Swap project
 * 
 * This file contains detailed Doxygen documentation for all functions in the
 * Push_Swap project. It is not meant to be included in the code, but rather
 * to be processed by Doxygen to generate documentation.
 */

/**
 * @brief Validates if all arguments are valid integers
 *
 * Checks for invalid characters, non-integer inputs,
 * duplicates, and numbers out of range.
 *
 * @param ac Argument count (excluding program name)
 * @param av Arguments array (excluding program name)
 * @return 1 if all arguments are valid, 0 otherwise
 */
int		num_checker(int ac, char **av);

/**
 * @brief Parses command line arguments into a stack
 *
 * Creates a new stack and fills it with the integer values
 * from the command line arguments.
 *
 * @param ac Argument count (excluding program name)
 * @param av Arguments array (excluding program name)
 * @return A pointer to the initialized stack, or NULL on error
 */
t_stack	*parse_args(int ac, char **av);

/**
 * @brief Initializes an empty stack with a given capacity
 *
 * @param capacity Maximum number of elements the stack can hold
 * @return A pointer to the initialized stack, or NULL on error
 */
t_stack	*stack_init(int capacity);

/**
 * @brief Pushes the top element from source stack to destination stack
 *
 * Takes the first element at the top of source and puts it at the top of
 * destination. Does nothing if source is empty.
 * When stack_name is 'a', implements 'pa' (push to stack a).
 * When stack_name is 'b', implements 'pb' (push to stack b).
 * 
 * @param src Source stack
 * @param dest Destination stack
 * @param stack_name 'a' for pa, 'b' for pb
 */
void	pa_pb(t_stack *src, t_stack *dest, char stack_name);

/**
 * @brief Swaps the top two elements of a stack
 *
 * Implements the 'sa', 'sb', 'ss' operations required by push_swap algorithm.
 * When stack_name is 'a', implements 'sa' (swap stack a).
 * When stack_name is 'b', implements 'sb' (swap stack b).
 * When stack_name is 's', implements 'ss' (swap both stacks).
 *
 * @param stack The stack to be manipulated
 * @param stack_name Character 'a', 'b', or 's' to determine which operation
 * to print
 * 
 * @note If the stack has 0 or 1 elements, the function does nothing.
 */
void	sa_sb(t_stack *stack, char stack_name);

/**
 * @brief Swaps the top two elements of both stacks simultaneously
 *
 * Implements the 'ss' operation required by push_swap algorithm.
 * Swaps both stack_a and stack_b in a single operation.
 *
 * @param stack_a First stack to swap
 * @param stack_b Second stack to swap
 * 
 * @note If either stack has 0 or 1 elements, the swap is not performed on that
 * stack, but may still be performed on the other stack if possible.
 */
void	ss(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Rotates a stack upward
 *
 * Implements the 'ra' and 'rb' operations required by push_swap algorithm.
 * When stack_name is 'a', implements 'ra' (rotate stack a).
 * When stack_name is 'b', implements 'rb' (rotate stack b).
 *
 * @param stack The stack to be manipulated
 * @param stack_name Character 'a' or 'b' to determine which operation to print
 * 
 * @note If the stack has 1 or 0 elements, the function does nothing.
 * 
 * @details Implementation:
 *   1. Checks if stack has enough elements to rotate
 *   2. Stores the first element in a temporary variable
 *   3. Shifts all elements up by 1 position
 *   4. Places the former first element at the bottom (last index)
 */
void	ra_rb(t_stack *stack, char stack_name);

/**
 * @brief Rotates both stacks upward simultaneously
 *
 * Implements the 'rr' operation required by push_swap algorithm.
 * Rotates both stack_a and stack_b upward in a single operation.
 *
 * @param stack_a First stack to rotate
 * @param stack_b Second stack to rotate
 * 
 * @note If both stacks have 1 or 0 elements, the function does nothing.
 */
void	rr(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Reverse rotates a stack
 *
 * Implements the 'rra' and 'rrb' operations required by push_swap algorithm.
 * When stack_name is 'a', implements 'rra' (reverse rotate stack a).
 * When stack_name is 'b', implements 'rrb' (reverse rotate stack b).
 *
 * @param stack The stack to be manipulated
 * @param stack_name Character 'a' or 'b' to determine which operation to print
 * 
 * @note If the stack has 1 or 0 elements, the function does nothing.
 * 
 * @details Implementation:
 *   1. Checks if stack has enough elements to rotate
 *   2. Stores the last element in a temporary variable
 *   3. Shifts all elements down by 1 position
 *   4. Places the former last element at the top (index 0)
 */
void	rra_rrb(t_stack *stack, char stack_name);

/**
 * @brief Reverse rotates both stacks simultaneously
 *
 * Implements the 'rrr' operation required by push_swap algorithm.
 * Reverse rotates both stack_a and stack_b in a single operation.
 *
 * @param stack_a First stack to reverse rotate
 * @param stack_b Second stack to reverse rotate
 * 
 * @note If both stacks have 1 or 0 elements, the function does nothing.
 */
void	rrr(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Returns the number of elements in a stack
 *
 * @param stack The stack to check
 * @return The number of elements in the stack
 */
int		stack_size(t_stack *stack);

/**
 * @brief Frees the memory allocated to a stack
 * 
 * @param stack Pointer to the stack pointer to be freed
 */
void	free_stack(t_stack **stack);

/**
 * @brief Prints the content of a stack
 * 
 * Utility function for debugging purposes.
 * 
 * @param stack The stack to print
 */
void	print_stack(t_stack *stack);

/**
 * @brief Checks if a stack is sorted in ascending order
 * 
 * @param stack The stack to check
 * @return 1 if the stack is sorted, 0 otherwise
 */
int		is_sorted(t_stack *stack);

/**
 * @brief Counts the total number of arguments after splitting space-separated values
 *
 * Iterates through the argument list and counts individual arguments,
 * including those that need to be split by spaces.
 *
 * @param ac Argument count
 * @param av Arguments array
 * @return Total number of arguments, or -1 on error
 */
int		count_args(int ac, char **av);

/**
 * @brief Frees memory allocated for a NULL-terminated array of strings
 *
 * Used for cleanup of dynamically allocated string arrays.
 *
 * @param arr Array of strings to free
 */
void	free_string_array(char **arr);

/**
 * @brief Processes a space-separated argument into individual arguments
 *
 * Splits a string by spaces and adds each component to the args array
 * starting at the given position.
 *
 * @param arg String to split
 * @param args Destination array for split components
 * @param pos Starting position in the destination array
 * @return New position after adding components, or -1 on error
 */
int		process_split_arg(char *arg, char **args, int pos);

/**
 * @brief Initializes an array to hold flattened arguments
 *
 * Allocates memory for a string array of the specified count plus
 * a NULL terminator.
 *
 * @param count Number of strings the array will hold
 * @return Pointer to the allocated array, or NULL on allocation failure
 */
char	**init_args_array(int count);

/**
 * @brief Processes command line arguments into a flat array
 *
 * Handles each argument, splitting those with spaces, and copies
 * all into a single flat array.
 *
 * @param ac Argument count
 * @param av Arguments array
 * @param args Destination array for processed arguments
 * @return 0 on success, -1 on error
 */
int		process_args(int ac, char **av, char **args);

#endif