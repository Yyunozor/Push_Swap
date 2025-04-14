/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:28:40 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 17:17:35 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign_abs(long *num, int base_len)
{
	if (*num < 0 && base_len == 10)
	{
		*num = -*num;
		return (1);
	}
	return (0);
}

char	*ft_itoa_base(int value, const char *base)
{
	char		*result;
	long		num;
	int			base_len;
	int			sign;
	int			num_len;

	if (!ft_isvalid_base(base, &base_len))
		return (NULL);
	num = (long)value;
	sign = ft_sign_abs(&num, base_len);
	num_len = ft_numlen_base(num, base_len) + sign;
	result = (char *)malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	while (num_len-- > sign)
	{
		result[num_len] = base[num % base_len];
		num /= base_len;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
