/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:59:08 by vlaine            #+#    #+#             */
/*   Updated: 2021/11/08 09:59:08 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				isp;
	long long int	atoiis;

	isp = 1;
	atoiis = 0;
	while ((*str && *str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isp *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoiis = atoiis * 10;
		atoiis = atoiis + *str - 48;
		if (isp * atoiis > 2147483647)
			return (-1);
		if (isp * atoiis < -2147483648)
			return (0);
		str++;
	}
	return (atoiis * isp);
}
