/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:15:30 by anpayot           #+#    #+#             */
/*   Updated: 2025/04/16 22:59:22 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Counts total number of arguments after splitting strings
 */
static int	count_args(int ac, char **av)
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

/**
 * Frees a string array (NULL terminated)
 */
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

/**
 * Creates a flat array of arguments, splitting any space-separated strings
 */
static char	**flatten_args(int ac, char **av, int *total_count)
{
    char	**args;
    char	**split;
    int		i;
    int		j;
    int		pos;

    *total_count = count_args(ac, av);
    if (*total_count < 0)
        return (NULL);
    args = malloc(sizeof(char *) * (*total_count + 1));
    if (!args)
        return (NULL);
    pos = 0;
    i = 0;
    while (i < ac)
    {
        if (ft_strchr(av[i], ' '))
        {
            split = ft_split(av[i], ' ');
            if (!split)
            {
                free_string_array(args);
                return (NULL);
            }
            j = 0;
            while (split[j])
                args[pos++] = ft_strdup(split[j++]);
            free_string_array(split);
        }
        else
            args[pos++] = ft_strdup(av[i]);
        i++;
    }
    args[pos] = NULL;
    return (args);
}

/**
 * Creates and initializes stack A with parsed arguments
 */
t_stack	*parse_args(int ac, char **av)
{
    t_stack	*stack_a;
    char	**args;
    int		total_count;
    int		i;

    args = flatten_args(ac, av, &total_count);
    if (!args)
        return (NULL);
    if (!validation(total_count, args))
    {
        free_string_array(args);
        return (NULL);
    }
    stack_a = stack_init(total_count);
    if (!stack_a)
    {
        free_string_array(args);
        return (NULL);
    }
    i = total_count - 1;
    while (i >= 0)
    {
        stack_a->data[stack_a->top++] = ft_atoi(args[i]);
        i--;
    }
    free_string_array(args);
    return (stack_a);
}
