/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/27 17:24:32 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_loverflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (ft_loverflow(sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	const char *str1 = "12345";
	const char *str2 = "-98765";
	const char *str3 = "0";
	const char *str4 = "2147483647"; // LONG_MAX
	const char *str5 = "-2147483648"; // LONG_MIN

	long num1 = ft_atol(str1);
	long num2 = ft_atol(str2);
	long num3 = ft_atol(str3);
	long num4 = ft_atol(str4);
	long num5 = ft_atol(str5);

	long orig_num1 = atol(str1);
	long orig_num2 = atol(str2);
	long orig_num3 = atol(str3);
	long orig_num4 = atol(str4);
	long orig_num5 = atol(str5);

	printf("1:\t%ld\t\tatol_libc:\t%ld\n", num1, orig_num1);
	printf("2:\t%ld\t\tatol_libc:\t%ld\n", num2, orig_num2);
	printf("3:\t%ld\t\tatol_libc:\t%ld\n", num3, orig_num3);
	printf("4:\t%ld\tatol_libc:\t%ld\n", num4, orig_num4);
	printf("5:\t%ld\tatol_libc:\t%ld\n", num5, orig_num5);

	return 0;
}
*/