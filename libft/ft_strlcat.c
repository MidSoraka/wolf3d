/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:16:46 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/20 13:02:30 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	digits;
	size_t	len;

	index = 0;
	digits = ft_strlen(dst);
	len = digits;
	while (len < dstsize - 1 && dstsize > 0 && src[index])
		dst[len++] = src[index++];
	if (dstsize > 0 && dstsize > len)
		dst[len] = '\0';
	if (dstsize > 0 && dstsize > len)
		index++;
	if (src[index] == '\0')
	{
		if (index != 0)
			len = index + digits;
	}
	else
		len = ft_strlen(src) + digits;
	if (index == 0)
		len = ft_strlen(src) + dstsize;
	if (index == 0 && ft_strlen(src) == 0)
		len = digits;
	return (len);
}
