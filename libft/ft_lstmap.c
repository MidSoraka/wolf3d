/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:48:06 by vlaine            #+#    #+#             */
/*   Updated: 2021/12/16 19:29:11 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(void *content, size_t size)
{
	if (size > 0)
		free(content);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*head;

	if ((f) == NULL || lst == NULL)
		return (NULL);
	list = (*f)(lst);
	head = list;
	lst = lst->next;
	while (lst != NULL)
	{
		list->next = (*f)(lst);
		if (list->next == NULL || head == NULL)
		{
			ft_lstdel(&head, ft_free);
			return (NULL);
		}
		list = list->next;
		lst = lst->next;
	}
	return (head);
}
