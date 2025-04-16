/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:29:53 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 22:54:59 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_int(char *str)
{
	long	num;

	if (!is_valid_number(str))
		return (0);
	num = ft_atol(str);
	return (num > INT_MIN && num <= INT_MAX);
}

static int	duplicated(int count, char **args)
{
	long	num1;
	long	num2;
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		num1 = ft_atol(args[i]);
		j = i + 1;
		while (j < count)
		{
			num2 = ft_atol(args[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validation(int ac, char **av)
{
	int	i;

	if (ac < 1)
		return (0);
	i = 0;
	while (i < ac)
	{
		if (!is_valid_int(av[i]))
			return (0);
		i++;
	}
	if (duplicated(ac, av))
		return (0);
	return (1);
}
