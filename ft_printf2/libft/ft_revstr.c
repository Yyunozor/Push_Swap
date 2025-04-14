/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:34:57 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/23 13:26:26 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str, size_t len)
{
	char	*start;
	char	*end;

	start = str;
	end = str + len - 1;
	while (start < end)
		ft_swap(start++, end--);
	return (str);
}
