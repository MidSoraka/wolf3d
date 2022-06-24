/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:01:29 by vlaine            #+#    #+#             */
/*   Updated: 2021/11/08 10:01:29 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	ii;

	i = 0;
	if (ft_strlen(needle) == 0)
		return (&((char *)haystack)[0]);
	while (haystack[i] != '\0' && i != len)
	{
		ii = 0;
		ptr = &((char *)haystack)[i];
		while ((haystack[i] == needle[ii]) && i != len)
		{
			if (needle[ii + 1] == '\0')
				return (ptr);
			ii++;
			i++;
		}
		i = i - ii;
		i++;
	}
	return (NULL);
}
