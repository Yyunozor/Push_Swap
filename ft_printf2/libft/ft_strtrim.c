/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:06:04 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/16 19:32:07 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	while (*start && ft_memchr(set, *start, ft_strlen(set)))
		start++;
	end = (char *)s1 + ft_strlen(s1);
	while (end > start && ft_memchr(set, *(end - 1), ft_strlen(set)))
		end--;
	return (ft_substr(start, 0, end - start));
}
