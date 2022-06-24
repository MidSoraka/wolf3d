/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:22:58 by vlaine            #+#    #+#             */
/*   Updated: 2022/01/05 14:49:10 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char **ptr, size_t n)
{
	char	*ptrcpy;

	ptrcpy = ft_strnew(n);
	if (*ptr != NULL)
	{
		ft_strcpy(ptrcpy, *ptr);
		free(*ptr);
	}
	return (ptrcpy);
}
