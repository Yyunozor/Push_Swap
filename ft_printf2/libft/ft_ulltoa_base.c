/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:46:46 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 03:50:38 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long value, const char *base)
{
	int		base_len;
	int		num_len;
	char	*result;

	if (!ft_isvalid_base(base, &base_len))
		return (NULL);
	num_len = ft_numlen_base(value, base_len);
	result = (char *)malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	while (num_len > 0)
	{
		result[--num_len] = base[value % base_len];
		value /= base_len;
	}
	return (result);
}
