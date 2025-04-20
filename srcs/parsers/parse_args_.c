/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:15:30 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/20 10:15:42 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Counts the total number of arguments after splitting
 * 
 * @param ac Number of arguments
 * @param av Array of argument strings
 * @return Total number of arguments or -1 on error
 */
static int	count_total_args(int ac, char **av)
{
	int		i;
	int		total;
	char	**split;
	int		j;

	total = 0;
	i = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			split = ft_split(av[i], ' ');
			if (!split)
				return (-1);
			j = 0;
			while (split[j++])
				total++;
			free_string_array(split);
		}
		else
			total++;
		i++;
	}
	return (total);
}

/**
 * @brief Process a single argument that contains spaces
 * 
 * @param arg The argument to process
 * @param result The array to store the parsed arguments
 * @param index Current position in result array
 * @return Updated index or -1 on error
 */
static int	process_space_arg(char *arg, char **result, int index)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (-1);
	j = 0;
	while (split[j])
	{
		result[index] = ft_strdup(split[j]);
		if (!result[index])
		{
			free_string_array(split);
			return (-1);
		}
		index++;
		j++;
	}
	free_string_array(split);
	return (index);
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
	int		i;
	int		index;

	*total_count = count_total_args(ac, av);
	if (*total_count < 0)
		return (NULL);
	args = malloc(sizeof(char *) * (*total_count + 1));
	if (!args)
		return (NULL);
	index = 0;
	i = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			index = process_space_arg(av[i], args, index);
		else
		{
			args[index] = ft_strdup(av[i]);
			if (!args[index])
				index = -1;
			else
				index++;
		}
		if (index == -1)
		{
			free_string_array(args);
			return (NULL);
		}
		i++;
	}
	args[index] = NULL;
	return (args);
}

/**
 * @brief Loads a stack with integer values from a flattened array of arguments.
 *
 * @param args The flattened array of arguments.
 * @param total_count The total number of arguments in the array.
 * @return A pointer to the initialized stack, or NULL if an error occurs.
 */
static t_stack	*load_stack(char **args, int total_count)
{
	t_stack	*stack_a;
	int		i;

	stack_a = stack_init(total_count);
	if (!stack_a)
		return (NULL);
	i = total_count - 1;
	while (i >= 0)
	{
		stack_a->data[stack_a->top++] = ft_atol(args[i]);
		i--;
	}
	return (stack_a);
}

/**
 * @brief Parse and validate command line arguments into a stack
 *
 * @param ac The argument count from the command line
 * @param av The argument vector from the command line
 * @return A pointer to the initialized stack, or NULL if an error occurs
 */
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
