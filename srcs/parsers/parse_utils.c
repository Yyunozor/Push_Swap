/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:30:00 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/09 10:28:31 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	process_space_arg(char *arg, char **result, int index)
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
			free_str_array(split);
			return (-1);
		}
		index++;
		j++;
	}
	free_str_array(split);
	return (index);
}

int	count_args(int ac, char **av)
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
			free_str_array(split);
		}
		else
			total++;
		i++;
	}
	return (total);
}

void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_stack	*load_stack(char **args, int total_count)
{
	t_stack	*stack_a;
	int		i;

	stack_a = stack_init(total_count);
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < total_count)
	{
		stack_a->data[stack_a->top++] = ft_atol(args[i]);
		i++;
	}
	return (stack_a);
}
