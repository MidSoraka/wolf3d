/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:57:26 by vlaine            #+#    #+#             */
/*   Updated: 2021/11/26 16:23:11 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *) s)[index] == ((unsigned char)c))
			return ((void *)s + index);
		index++;
	}
	return (NULL);
}
