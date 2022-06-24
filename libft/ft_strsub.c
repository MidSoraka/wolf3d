/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:46:00 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/16 20:01:40 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	digits;

	digits = 0;
	str = (char *) malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (digits != len)
	{
		str[digits] = s[start + digits];
		digits++;
	}
	str[digits] = '\0';
	return (str);
}
