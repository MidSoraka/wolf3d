/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:33:07 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/08 13:11:23 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_revnbr(size_t n, size_t digits)
{
	size_t	nbr;
	char	c;

	nbr = 0;
	while (n != 0)
	{
		nbr = nbr * 10 + (n % 10);
		n = n / 10;
	}
	while (nbr != 0)
	{
		c = nbr % 10;
		nbr = nbr / 10;
		ft_putchar(c + '0');
		digits--;
	}
	return (digits);
}

void	ft_putnbr(int n)
{
	size_t	nbr;
	size_t	ncpy;
	size_t	digits;
	int		iszero;

	digits = ft_digits(n);
	nbr = 0;
	iszero = 0;
	if (n < 0)
		ft_putchar('-');
	ncpy = ft_topos(n);
	if (digits > 0)
		iszero = 1;
	digits = ft_revnbr(ncpy, digits);
	while (digits > 0)
	{
		ft_putchar('0');
		digits--;
	}
	if (ncpy % 10 == 0 && iszero == 0)
	{
		ft_putchar('0');
	}
}
