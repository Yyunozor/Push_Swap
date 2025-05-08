/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:15:30 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 01:57:29 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Handles a single string argument that contains spaces
 *
 * Splits a space-separated string into an array of arguments and counts them.
 *
 * @param arg String containing space-separated values
 * @param count Pointer to store the count of arguments after splitting
 * @return Array of strings representing split arguments, or NULL on error
 */
static char	**split_strarg(char *arg, int *count)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		return (NULL);
	*count = 0;
	while (args[*count])
		(*count)++;
	return (args);
}

/**
 * @brief Extracts arguments from command line parameters
 *
 * Handles both space-separated single argument and multiple arguments cases.
 *
 * @param ac Argument count
 * @param av Array of argument strings
 * @param total_count Pointer to store the total count of arguments
 * @return Array of argument strings, or NULL on error
 */
static char	**extract_args(int ac, char **av, int *total_count)
{
	char	**args;

	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		args = split_strarg(av[1], total_count);
		if (!args)
			return (NULL);
	}
	else
	{
		*total_count = ac - 1;
		args = av + 1;
	}
	return (args);
}

/**
 * @brief Handles memory cleanup and returns the stack
 *
 * Frees memory allocated for arguments if needed before returning the stack.
 *
 * @param ac Argument count
 * @param args Array of argument strings to free (if applicable)
 * @param stack Stack to return
 * @return The input stack pointer
 */
static t_stack	*freeturn(int ac, char **args, t_stack *stack)
{
	if (ac == 2 && args != NULL)
		free_str_array(args);
	return (stack);
}

t_stack	*parse_args(int ac, char **av)
{
	char	**args;
	int		total_count;
	t_stack	*stack;
	int		is_single_arg;

	if (ac < 2)
		return (NULL);
	is_single_arg = (ac == 2 && ft_strchr(av[1], ' '));
	args = extract_args(ac, av, &total_count);
	if (!args)
		return (NULL);
	if (!num_checker(total_count, args))
	{
		if (is_single_arg)
			return (freeturn(ac, args, NULL));
		else
			return (freeturn(ac, NULL, NULL));
	}
	stack = load_stack(args, total_count);
	if (is_single_arg)
		return (freeturn(ac, args, stack));
	else
		return (freeturn(ac, NULL, stack));
}
