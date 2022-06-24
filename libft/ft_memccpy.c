/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:18:44 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/16 19:52:59 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)src)[index] != (unsigned char)c)
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		if (((unsigned char *)src)[index] == (unsigned char)c)
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			return (dst + index + 1);
		}
		index++;
	}
	return (NULL);
}
