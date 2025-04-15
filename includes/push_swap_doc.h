/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_doc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:00:00 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 01:05:04 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DOC_H
# define PUSH_SWAP_DOC_H

/**
 * @file push_swap_doc.h
 * @brief Documentation-only header file for Push_Swap project
 * 
 * This file contains detailed Doxygen documentation for all functions in the
 * Push_Swap project. It is not meant to be included in the code, but rather
 * to be processed by Doxygen to generate documentation.
 */

/**
 * @brief Moves the top element from source stack to destination stack
 *
 * Implements the 'pa' and 'pb' operations required by push_swap algorithm.
 * When stack_name is 'a', implements 'pa' (push to stack a).
 * When stack_name is 'b', implements 'pb' (push to stack b).
 *
 * @param src The source stack to take the element from
 * @param dest The destination stack to place the element on top of
 * @param stack_name Character 'a' or 'b' to determine which operation to print
 * 
 * @note If the source stack is empty, the function does nothing.
 * 
 * @details Implementation:
 *   1. Checks if source stack is empty
 *   2. Shifts destination stack elements to make space
 *   3. Moves top element from source to destination
 *   4. Updates stack sizes accordingly
 *   5. Prints the operation ('pa' or 'pb')
 *
 * @complexity Time: O(n) where n is the max size of source or destination
 * @complexity Space: O(1)
 */
void	push(t_stack *src, t_stack *dest, char stack_name);

/**
 * @brief Initializes a new stack with the specified capacity
 *
 * @param capacity Maximum number of elements the stack can hold
 * @return Pointer to the newly created stack or NULL if allocation fails
 * 
 * @details
 * Creates and allocates memory for a new stack structure with the specified
 * maximum capacity.
 * - Allocates memory for the stack structure
 * - Allocates memory for the stack's internal array of integers
 * - Initializes size to 0 and sets the maximum capacity
 * - Returns NULL if any memory allocation fails
 * 
 * @note Time complexity: O(1)
 * @note Space complexity: O(capacity)
 */
t_stack	*stack_init(int capacity);

#endif