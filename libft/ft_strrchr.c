/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:01:40 by vlaine            #+#    #+#             */
/*   Updated: 2021/11/08 10:01:40 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*ptr;

	index = 0;
	ptr = NULL;
	while (s[index])
	{
		if (s[index] == (char)c)
			ptr = (&((char *)s)[index]);
		index++;
	}
	if (s[index] == (char)c)
		ptr = (&((char *)s)[index]);
	if (ptr != NULL)
		return (ptr);
	else
		return (NULL);
}
