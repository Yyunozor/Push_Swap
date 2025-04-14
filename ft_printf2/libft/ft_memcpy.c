/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:11:39 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/09 15:42:50 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (!dst && !src && n > 0)
		return (NULL);
	p_dst = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}
