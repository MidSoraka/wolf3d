/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:14:33 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/20 12:23:26 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	if ((ft_strlen(s1) == 0 && ft_strlen(s2) == 0) || n == 0)
		return (1);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (0);
	while (s1[index] && s2[index] && index < n)
	{
		if (((unsigned char)s1[index] - (unsigned char)s2[index]) != 0)
		{
			return (0);
		}
		index++;
	}
	if (index != n)
	{
		if (((unsigned char)s1[index] - (unsigned char)s2[index]) != 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}
