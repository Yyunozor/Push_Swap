/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:19:02 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/23 19:27:12 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;

	ch = (unsigned char)c;
	str = (const unsigned char *)s;
	while (n--)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
