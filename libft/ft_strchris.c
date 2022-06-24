/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:15:51 by vlaine            #+#    #+#             */
/*   Updated: 2022/01/05 14:22:05 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchris(const char *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0' && index < n)
	{
		if (s[index] == (char)c)
			return (1);
		index++;
	}
	if (s[index] == (char)c)
		return (1);
	else
		return (0);
}
