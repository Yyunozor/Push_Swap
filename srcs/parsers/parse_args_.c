/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:15:30 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/19 18:40:41 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char	**flatten_args(int ac, char **av, int *total_count)
{
	char	**args;

	*total_count = count_args(ac, av);
	if (*total_count < 0)
		return (NULL);
	args = init_args_array(*total_count);
	if (!args)
		return (NULL);
	if (process_args(ac, av, args) == -1)
		return (NULL);
	return (args);
}

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
		stack_a->data[stack_a->top++] = ft_atoi(args[i]);
		i--;
	}
	return (stack_a);
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
