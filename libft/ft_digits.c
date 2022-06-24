/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:16:41 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/08 13:16:42 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digits(int n)
{
	size_t	digits;
	size_t	ncpy;

	digits = 1;
	ncpy = ft_topos(n);
	while (ncpy > 9)
	{
		ncpy = ncpy / 10;
		digits++;
	}
	return (digits);
}
