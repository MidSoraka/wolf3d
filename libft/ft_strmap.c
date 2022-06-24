/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:33:12 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/08 12:38:37 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	char	*str;

	index = 0;
	while (s[index])
		index++;
	str = (char *) malloc(index * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = s[index];
		str[index] = ((*f)(str[index]));
		index++;
	}
	str[index] = '\0';
	return (str);
}
