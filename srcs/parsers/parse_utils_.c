/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:30:00 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/19 18:23:40 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_args(int ac, char **av)
{
	int		i;
	int		total;
	char	**split;

	total = 0;
	i = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			split = ft_split(av[i], ' ');
			if (!split)
				return (-1);
			while (split[total])
				total++;
			free_string_array(split);
		}
		else
			total++;
		i++;
	}
	return (total);
}

void	free_string_array(char **arr)
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

int	process_split_arg(char *arg, char **args, int pos)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
	{
		free_string_array(args);
		return (-1);
	}
	j = 0;
	while (split[j])
		args[pos++] = ft_strdup(split[j++]);
	free_string_array(split);
	return (pos);
}

char	**init_args_array(int count)
{
	char	**args;

	args = malloc(sizeof(char *) * (count + 1));
	return (args);
}

int	process_args(int ac, char **av, char **args)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			pos = process_split_arg(av[i], args, pos);
			if (pos == -1)
				return (-1);
		}
		else
			args[pos++] = ft_strdup(av[i]);
		i++;
	}
	args[pos] = NULL;
	return (0);
}
