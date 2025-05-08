/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_comm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/04/27 12:20:19 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 01:15:23 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_COMM_H
# define FUNC_COMM_H

# include "push_swap.h"

/**
 * @file func_comm.h
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
 * from the command line arguments. Handles both space-separated
 * single arguments and multiple arguments. Validates all inputs
 * before creating the stack.
 *
 * @param ac Argument count (including program name)
 * @param av Arguments array (including program name)
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
 * @brief Counts the total number of arguments after splitting
 *
 * Determines the total number of arguments when all space-separated values
 * are considered as individual arguments.
 *
 * @param ac Number of arguments
 * @param av Array of argument strings
 * @return Total number of arguments, or -1 on error
 */
int		count_args(int ac, char **av);

/**
 * @brief Frees memory allocated for an array of strings
 * 
 * Used for cleanup of dynamically allocated string arrays.
 *
 * @param arr Array of strings to free
 */
void	free_string_array(char **arr);

/**
 * @brief Process a single argument that contains spaces
 * 
 * Splits a string by spaces and adds each component to the result array
 * starting at the given position.
 *
 * @param arg String to split
 * @param result Destination array for split components
 * @param index Current position in the destination array
 * @return Updated index after adding components, or -1 on error
 */
int		process_space_arg(char *arg, char **result, int index);

/**
 * @brief Loads a stack with integer values from a flattened array of arguments
 *
 * Creates a new stack and populates it with the parsed integers,
 * placing them in reverse order to maintain the correct order in the stack.
 *
 * @param args The flattened array of arguments
 * @param total_count The total number of arguments in the array
 * @return A pointer to the initialized stack, or NULL if an error occurs
 */
t_stack	*load_stack(char **args, int total_count);

/**
 * @brief Sorts a stack of 3 or fewer elements
 *
 * Uses a direct approach with specific operations determined by the 
 * relative order of the elements. The algorithm handles all possible 
 * permutations of 3 elements optimally.
 *
 * @param stack The stack to be sorted
 */
void	sort_3(t_stack *stack);

/**
 * @brief Sorts a stack of 5 or fewer elements
 * 
 * Uses a strategy of pushing the smallest elements to stack_b,
 * sorting the remaining 3 elements in stack_a using sort_3,
 * then pushing elements back from stack_b to stack_a.
 *
 * @param stack_a The main stack to be sorted
 * @param stack_b The auxiliary stack for the sorting process
 */
void	sort_5(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Sorts a medium-sized stack (typically 6-100 elements)
 * 
 * Implements a more complex algorithm for medium-sized stacks, using a
 * chunk-based strategy. The algorithm divides the elements into chunks
 * based on their sorted positions, pushing them to stack_b in order,
 * and then pushes them back to stack_a in sorted order.
 *
 * @param stack_a The main stack to be sorted
 * @param stack_b The auxiliary stack for the sorting process
 */
void	sort_medium(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Sorts a large stack (typically more than 100 elements)
 * 
 * Implements an efficient radix sort algorithm for large stacks,
 * which involves normalizing the values and then sorting them
 * by binary representation. This approach provides consistent
 * and predictable performance for large datasets.
 *
 * @param stack_a The main stack to be sorted
 * @param stack_b The auxiliary stack for the sorting process
 */
void	sort_large(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Creates a copy of a stack's data array
 * 
 * Allocates memory for a new array and copies the data from the stack
 * into it. This is primarily used for operations that need to 
 * manipulate a copy of the stack's data rather than the stack itself.
 *
 * @param stack The stack to copy from
 * @param size The number of elements to copy
 * @return A pointer to the newly allocated array, or NULL if allocation fails
 */
int *copy_stack(t_stack *stack, int size);

/**
 * @brief Finds the position of a specific value in a stack
 * 
 * Searches through the stack to locate a specific value and returns
 * its position in the stack. This is used for targeted operations
 * that need to know where a specific element is located.
 *
 * @param stack The stack to search in
 * @param value The value to find
 * @return The position of the value, or -1 if not found
 */
int	find_position(t_stack *stack, int value);

/**
 * @brief Moves an element at a specific position to the top of the stack
 * 
 * Uses rotation operations (ra/rb or rra/rrb) to move an element
 * at a specific position to the top of the stack using the most
 * efficient sequence of operations.
 *
 * @param stack The stack to manipulate
 * @param pos The position of the element to move
 * @param stack_id Identifier for the stack ('a' or 'b')
 */
void	move_to_top(t_stack *stack, int pos, char stack_id);

/**
 * @brief Performs a bubble sort on an integer array
 * 
 * This utility function is used for sorting operations that need
 * to work with a sorted copy of the stack data, particularly
 * for the normalization process in the radix sort algorithm.
 *
 * @param arr The array to sort
 * @param size The size of the array
 */
void	bubble_sort_arr(int *arr, int size);

/**
 * @brief Copies the stack data to a new integer array
 * 
 * This function allocates memory for a new array and copies
 * the data from the stack to this array.
 * 
 * @param stack The stack to copy from
 * @param size The number of elements to copy
 * @return A pointer to the newly allocated array
 */
int	*copy_stack(t_stack *stack, int size);

/**
 * @brief Finds the minimum value in a stack
 * 
 * This function iterates through the stack to find the
 * position of the minimum value.
 * 
 * @param stack The stack to search
 * @return The position of the minimum value
 */
int	min_finder(t_stack *stack);

/**
 * @brief Finds the maximum value in a stack
 * 
 * This function iterates through the stack to find the
 * position of the maximum value.
 * 
 * @param stack The stack to search
 * @return The position of the maximum value
 */
int	max_finder(t_stack *stack);

/**
 * @brief Moves the minimum value to the top of the stack
 * 
 * This function finds the minimum value in the stack and
 * performs rotation operations to bring it to the top position.
 * 
 * @param stack The stack to manipulate
 * @param stack_id Identifier for the stack ('a' or 'b')
 */
void	min_to_top(t_stack *stack, char stack_id);

/**
 * @brief Moves the maximum value to the top of the stack
 * 
 * This function finds the maximum value in the stack and
 * performs rotation operations to bring it to the top position.
 * 
 * @param stack The stack to manipulate
 */
void	max_to_top(t_stack *stack);

/**
 * @brief Checks if a string represents a valid integer
 * 
 * Verifies that a string contains only digits and an optional sign,
 * with no other characters, and that the value fits within the 
 * allowed integer range.
 *
 * @param str The string to validate
 * @return 1 if the string is a valid integer, 0 otherwise
 */
int	is_valid_int(char *str);

/**
 * @brief Checks for duplicate values in an array
 * 
 * Verifies that all values in the array are unique, which is a
 * requirement for the push_swap problem.
 *
 * @param arr The array to check
 * @param size The size of the array
 * @return 1 if duplicates are found, 0 if all values are unique
 */
int	has_duplicates(int *arr, int size);

/**
 * @brief Counts the number of bits needed to represent a number
 *
 * Determines the minimum number of bits required to represent
 * the provided integer in binary format. This is used by the
 * radix sort algorithm to determine how many bit positions
 * need to be processed.
 *
 * @param num The number to analyze
 * @return The number of bits required
 */
int	count_bits(int num);

/**
 * @brief Performs a binary radix sort on the stack
 *
 * This is the core implementation of the radix sort algorithm.
 * It sorts numbers by processing them bit by bit, from the least
 * significant bit (LSB) to the most significant bit (MSB).
 * For each bit position, it distributes elements between stacks
 * based on whether the bit is 0 or 1, and then recombines them.
 *
 * @param stack_a First stack
 * @param stack_b Second stack
 * @param size Number of elements to sort
 * @param max_bits Maximum number of bits to process
 */
void	radix_sort_bits(t_stack *stack_a, t_stack *stack_b,
						int size, int max_bits);

/**
 * @brief Performs bubble sort on an integer array
 * 
 * This function sorts an array of integers using the bubble sort algorithm.
 * The result is arranged in ascending order.
 * 
 * @param arr The array to sort
 * @param size The size of the array
 */
void	bubble_sort_arr(int *arr, int size);

#endif