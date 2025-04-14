/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:42:13 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 03:50:25 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen_base(unsigned long long num, int base_len)
{
	int	len;

	len = (num == 0);
	while (num != 0)
	{
		num /= base_len;
		len++;
	}
	return (len);
}
