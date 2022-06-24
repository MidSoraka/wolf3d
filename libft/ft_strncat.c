/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:16:46 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/16 19:54:16 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	digits;

	digits = 0;
	index = 0;
	while (s1[digits])
		digits++;
	while (index != n && s2[index])
	{
		s1[digits + index] = s2[index];
		index++;
	}
	s1[digits + index] = '\0';
	return (s1);
}
