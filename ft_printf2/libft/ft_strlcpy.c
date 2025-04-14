/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:56:15 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/10 15:21:47 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*src_start = src;

	if (dstsize)
	{
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	while (*src++)
		;
	return (src - src_start - 1);
}
