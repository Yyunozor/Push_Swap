/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:24:43 by anpayot           #+#    #+#             */
/*   Updated: 2025/01/10 11:10:03 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **arr, char **ptr)
{
	while (ptr-- > arr)
		free(*ptr);
	free(arr);
}

static size_t	ft_counter(const char *s, char c)
{
	size_t		count;
	const char	*ptr;

	count = 0;
	ptr = s;
	while (*ptr)
	{
		if (*ptr != c && (*(ptr + 1) == c || !*(ptr + 1)))
			count++;
		ptr++;
	}
	return (count);
}

static char	*ft_nxtwrd(const char **s, char c)
{
	const char	*start;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	return (ft_substr(start, 0, *s - start));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_counter(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (words--)
	{
		*ptr = ft_nxtwrd(&s, c);
		if (!*ptr++)
			return (ft_free(res, ptr - 1), NULL);
	}
	*ptr = NULL;
	return (res);
}
