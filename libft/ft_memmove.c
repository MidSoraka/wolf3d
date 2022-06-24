/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:18:44 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/16 20:05:21 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (dst == NULL && src == NULL)
		return (NULL);
	index = 0;
	if (src < dst)
	{
		while (0 != len)
		{
			len--;
			((char *)dst)[len] = (((char *)src)[len]);
		}
	}
	else if (dst < src)
	{
		while (index < len)
		{
			((char *)dst)[index] = (((char *)src)[index]);
			index++;
		}
	}
	return (dst);
}
