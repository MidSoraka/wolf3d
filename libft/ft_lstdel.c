/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:30:31 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/02 22:52:18 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	while (*alst != NULL)
	{
		list = *alst;
		*alst = list->next;
		(*del)(list->content, list->content_size);
		free(list);
	}
	*alst = NULL;
	free(*alst);
}
