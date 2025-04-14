/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:45:05 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/08 22:08:14 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == 0 || haystack == needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && needle_len <= len--)
	{
		if (!(ft_strncmp((char *)haystack, (char *)needle, needle_len)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
