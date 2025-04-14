/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_xxl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:24:24 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/08 14:50:13 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_forward(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t			*d_word;
	const size_t	*s_word;

	if ((size_t)d % sizeof(size_t) == (size_t)s % sizeof(size_t))
	{
		d_word = (size_t *)d;
		s_word = (const size_t *)s;
		while (len >= sizeof(size_t))
		{
			*d_word++ = *s_word++;
			len -= sizeof(size_t);
		}
		d = (unsigned char *)d_word;
		s = (const unsigned char *)s_word;
	}
	while (len--)
		*d++ = *s++;
}

static void	copy_backward(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t			*d_word;
	const size_t	*s_word;

	if ((size_t)d % sizeof(size_t) == (size_t)s % sizeof(size_t))
	{
		d_word = (size_t *)(d + len);
		s_word = (const size_t *)(s + len);
		while (len >= sizeof(size_t))
		{
			len -= sizeof(size_t);
			*--d_word = *--s_word;
		}
		d = (unsigned char *)d_word;
		s = (const unsigned char *)s_word;
	}
	while (len--)
		d[len] = s[len];
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		copy_forward((unsigned char *)dst, (const unsigned char *)src, len);
	else
		copy_backward((unsigned char *)dst, (const unsigned char *)src, len);
	return (dst);
}
