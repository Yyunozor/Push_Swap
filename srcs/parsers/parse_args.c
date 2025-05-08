/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:15:30 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/03 00:24:57 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *parse_args(int ac, char **av)
{
	char    **args;
	int     total_count;
	t_stack *stack;
	
	if (ac < 2)
		return (NULL);
	
	// Handle both single string with spaces and multiple arguments
	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		// Single argument with spaces (e.g., "./push_swap "1 2 3"")
		args = ft_split(av[1], ' ');
		if (!args)
			return (NULL);
		total_count = 0;
		while (args[total_count])
			total_count++;
	}
	else
	{
		// Multiple individual arguments (e.g., "./push_swap 1 2 3")
		total_count = ac - 1;
		args = av + 1;  // Skip program name
	}
	
	// Validate numbers
	if (!num_checker(total_count, args))
	{
		if (ac == 2 && ft_strchr(av[1], ' '))
			free_string_array(args);
		return (NULL);
	}
	
	// Load into stack
	stack = load_stack(args, total_count);
	
	// Clean up if we allocated memory for args
	if (ac == 2 && ft_strchr(av[1], ' '))
		free_string_array(args);
	
	return (stack);
}
