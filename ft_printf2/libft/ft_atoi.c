/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 01:11:00 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/25 11:37:07 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		if (result * sign > 2147483647)
			return (2147483647);
		if (result * sign < -2147483648)
			return (-2147483648);
		nptr++;
	}
	return ((int)(result * sign));
}
