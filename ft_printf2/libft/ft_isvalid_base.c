/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:41:25 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/23 13:52:35 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_isvalid_base(const char *base, int *base_len)
{
	const char	*ptr;

	*base_len = ft_strlen(base);
	if (*base_len < 2)
		return (0);
	ptr = base;
	while (*ptr)
	{
		if (*ptr == '+' || *ptr == '-' || ft_isspace(*ptr))
			return (0);
		if (ft_strchr(ptr + 1, *ptr))
			return (0);
		ptr++;
	}
	return (1);
}
