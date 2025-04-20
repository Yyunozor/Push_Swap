/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:15:30 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/20 11:34:45 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Process a single non-space argument
 * 
 * @param arg Argument to process
 * @param result Result array
 * @param index Current index in the result array
 * @return Updated index or -1 on error
 */
static int	process_normal_arg(char *arg, char **result, int index)
{
	result[index] = ft_strdup(arg);
	if (!result[index])
		return (-1);
	return (index + 1);
}

/**
 * @brief Process all arguments and populate the args array
 * 
 * @param ac Number of arguments
 * @param av Array of arguments
 * @param args Result array to populate
 * @return 0 on success, -1 on failure
 */
static int	process_all_args(int ac, char **av, char **args)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			index = process_space_arg(av[i], args, index);
		else
			index = process_normal_arg(av[i], args, index);
		if (index == -1)
			return (-1);
		i++;
	}
	args[index] = NULL;
	return (0);
}

/**
 * @brief Flattens the command-line arguments into a single array of strings.
 *
 * @param ac The argument count from the command line.
 * @param av The argument vector from the command line.
 * @param total_count Pointer to an integer where the total count of arguments
 * will be stored.
 * @return A pointer to the flattened array of arguments, or NULL if error
 */
static char	**flatten_args(int ac, char **av, int *total_count)
{
	char	**args;

	*total_count = count_args(ac, av);
	if (*total_count < 0)
		return (NULL);
	args = malloc(sizeof(char *) * (*total_count + 1));
	if (!args)
		return (NULL);
	if (process_all_args(ac, av, args) == -1)
	{
		free_string_array(args);
		return (NULL);
	}
	return (args);
}

t_stack	*parse_args(int ac, char **av)
{
	t_stack	*stack_a;
	char	**args;
	int		total_count;

	args = flatten_args(ac, av, &total_count);
	if (!args)
		return (NULL);
	if (!num_checker(total_count, args))
	{
		free_string_array(args);
		return (NULL);
	}
	stack_a = load_stack(args, total_count);
	if (!stack_a)
	{
		free_string_array(args);
		return (NULL);
	}
	free_string_array(args);
	return (stack_a);
}
