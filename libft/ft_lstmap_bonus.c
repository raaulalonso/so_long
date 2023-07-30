/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:19:32 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/12 19:08:25 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	t_list	*tmp;

	if (lst)
	{
		head = ft_lstnew(f(lst->content));
		if (!head)
			return (0);
		tmp = lst->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (!new)
			{
				ft_lstclear(&tmp, del);
				return (0);
			}
			ft_lstadd_back(&head, new);
			tmp = tmp->next;
		}
		return (head);
	}
	return (0);
}
