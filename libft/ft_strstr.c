/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:01:46 by vlaine            #+#    #+#             */
/*   Updated: 2021/11/08 10:01:46 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	size_t	index;
	size_t	undex;

	index = 0;
	if (ft_strlen(needle) == 0)
		return (&((char *)haystack)[0]);
	while (haystack[index] != '\0')
	{
		undex = 0;
		ptr = &((char *)haystack)[index];
		while (haystack[index] == needle[undex])
		{
			if (needle[undex + 1] == '\0')
				return (ptr);
			undex++;
			index++;
		}
		index = index - undex;
		index++;
	}
	return (NULL);
}
