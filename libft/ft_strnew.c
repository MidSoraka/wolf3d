/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:14:57 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/16 23:38:14 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	index;

	index = 0;
	arr = (char *) malloc(size * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);
	else
		ft_bzero(arr, size + 1);
	return (arr);
}
