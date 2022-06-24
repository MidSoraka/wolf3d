/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:29:35 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/20 13:38:37 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		digits1;
	int		digits2;

	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	digits1 = 0;
	digits2 = 0;
	while (s1[digits1])
	{
		str[digits1] = s1[digits1];
		digits1++;
	}
	while (s2[digits2])
	{
		str[digits1] = s2[digits2];
		digits1++;
		digits2++;
	}
	str[digits1] = '\0';
	return (str);
}
