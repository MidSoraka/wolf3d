/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:54:35 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/20 13:39:47 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlength(size_t n, int neg)
{
	size_t	digits;

	digits = 1;
	if (neg == -1)
		digits++;
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int			neg;
	size_t		digits;
	size_t		nbr;
	char		*ptr;

	neg = 1;
	nbr = ft_topos(n);
	if (n < 0)
		neg = -1;
	digits = (ft_strlength(nbr, neg));
	ptr = (char *) malloc(digits * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[digits] = '\0';
	while (digits > 0)
	{
		ptr[digits - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		digits--;
	}
	if (neg == -1)
		ptr[digits] = '-';
	return (ptr);
}
