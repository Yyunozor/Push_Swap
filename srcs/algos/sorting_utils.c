/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:42:38 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/01 14:59:18 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*copy_stack(t_stack *stack, int size)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * size);
	if(!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = stack->data[i];
		i++;
	}
	return(copy);
}

int	min_finder(t_stack *stack)
{
	int	i;
	int	min_idx;
	int	min_val;
	
	if (stack->top == 0)
		return (-1);
	min_val = stack->data[0];
	min_idx = 0;
	i = 1;
	while (i < stack ->top)
	{
		if (stack->date[i] < min_val)
		{
			min_val = stack->data[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	max_finder(t_stack *stack)
{
	int	i;
	int	max_idx;
	int	max_val;

	if (stack->top == 0)
		return (-1);
	max_val = stack->data[0];
	max_idx = 0;
	i = 1;
	while (i < stack->top)
	{
		if (stack->data[i] > max_val)
		{
			max_val = stack->data[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

void	min_to_top(t_stack *stack)
{
	int	min_idx;

	min_idx = min_finder(stack);
	if (min_idx <= stack->top / 2)
	{
		while (min_idx > 0)
		{
			ra_rb(stack, 'a');
			min_idx--;
		}
	}
	else
	{
		while (min_pos < stack->top)
		{
			rra_rrb(stack, 'a');
			min_idx++;
		}
	}
}

int	pos_finder(t_stack *stack, int value)
{
	int	i;
	
	i = 0;
	while(i < stack->top)
	{
		if (stack->data[i] == value)
			return (i);
	}
	return (-1);
}

void	move_to_top(t_stack *stack, int pos, char stack_id)
{
	if (pos <= stack->top / 2)
	{
		while (pos > 0)
		{
			ra_rb(stack, stack_id);
			pos--;
		}
	}
	else
	{
		while (pos >< stack->top)
		{
			rra_rrb(stack, stack_id);
			pos++;
		}
	}
}