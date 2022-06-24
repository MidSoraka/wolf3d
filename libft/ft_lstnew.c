/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 05:56:00 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/20 12:21:32 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	size_t	index;

	index = 0;
	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = malloc(content_size);
	if (list->content == NULL || (void *)content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		if ((void *)content == NULL)
			return (list);
		free(list);
		return (NULL);
	}
	while (content_size >= index++)
		((char *)list->content)[index - 1] = ((char *)content)[index - 1];
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
