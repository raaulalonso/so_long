/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:59:33 by raalonso          #+#    #+#             */
/*   Updated: 2023/04/08 00:53:43 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*next;

	aux = *lst;
	while (aux)
	{
		next = aux->next;
		ft_lstdelone(aux, del);
		aux = next;
	}
	(*lst) = 0;
}
