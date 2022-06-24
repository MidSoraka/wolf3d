/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:51:48 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/20 13:38:16 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s)
{
	size_t	index;
	size_t	start;

	start = 0;
	index = 0;
	while (index != 1)
	{
		if (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		else
			index = 1;
	}
	return (start);
}

static int	ft_end(char const *s, int digits)
{
	size_t	index;

	index = 0;
	while (index != 1)
	{
		if (s[digits] == ' ' || s[digits] == '\n' || s[digits] == '\t')
			digits--;
		else
			index = 1;
	}
	return (digits);
}

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		digits;
	int		start;
	int		index;

	digits = ft_strlen(s) - 1;
	start = ft_start(s);
	digits = ft_end(s, digits);
	digits = digits - start;
	digits++;
	if (digits < 0)
		digits = 0;
	index = 0;
	str = (char *) malloc((digits) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (index != digits)
	{
		str[index] = s[index + start];
		index++;
	}
	str[index] = '\0';
	return (str);
}
