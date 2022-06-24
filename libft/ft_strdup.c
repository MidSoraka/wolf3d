/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:36:48 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/20 13:38:45 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		digits;
	char	*str;

	digits = 0;
	while (s1[digits])
	{
		digits++;
	}
	str = (char *) malloc(digits * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	digits = 0;
	while (s1[digits])
	{
		str[digits] = s1[digits];
		digits++;
	}
	str[digits] = '\0';
	return (str);
}
