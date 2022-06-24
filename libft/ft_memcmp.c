/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:13:30 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/03 00:44:53 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	a;
	unsigned char	b;

	index = 0;
	if ((unsigned int) n == 0)
		return (0);
	while (index < n)
	{
		a = ((unsigned char *)s1)[index];
		b = ((unsigned char *)s2)[index];
		if (a - b != 0)
			return (a - b);
		index++;
	}
	return (a - b);
}
