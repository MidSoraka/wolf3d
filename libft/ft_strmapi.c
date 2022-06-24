/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:08:18 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/03 03:35:59 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
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
		str[index] = ((*f)(index, s[index]));
		index++;
	}
	str[index] = '\0';
	return (str);
}
