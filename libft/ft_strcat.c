/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:36:41 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/16 19:53:37 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	index;
	int	digits;

	digits = 0;
	index = 0;
	while (s1[digits])
		digits++;
	while (s2[index])
	{
		s1[digits + index] = s2[index];
		index++;
	}
	s1[digits + index] = '\0';
	return (s1);
}
