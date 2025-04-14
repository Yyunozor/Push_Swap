/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/03 13:52:32 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lloverflow(int sign)
{
	if (sign == 1)
		return (LLONG_MAX);
	return (LLONG_MIN);
}

long	ft_atoll(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = ft_skspace(str);
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result > (LLONG_MAX - (str[i] - '0')) / 10)
			return (ft_lloverflow(sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
