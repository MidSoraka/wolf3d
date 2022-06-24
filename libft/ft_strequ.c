/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:14:33 by vlaine            #+#    #+#             */
/*   Updated: 2021/11/26 11:51:32 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	index;

	index = 0;
	while (s1[index])
	{
		if ((s1[index] - s2[index]) != 0)
		{
			return (0);
		}
		index++;
	}
	if ((s1[index] - s2[index]) != 0)
		return (0);
	else
		return (1);
}
