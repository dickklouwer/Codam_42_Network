/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:53:00 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/21 13:13:54 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;

	if (!lst || !del)
		return (NULL);
	new_head = 0;
	while (lst != NULL)
	{
		new_node = ft_lstnew (f(lst->content));
		if (!new_node)
		{
			ft_lstclear (&new_head, del);
			return (0);
		}
		ft_lstadd_back (&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}
