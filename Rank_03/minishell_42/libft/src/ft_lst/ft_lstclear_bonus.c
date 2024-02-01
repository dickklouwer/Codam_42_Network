/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:52:27 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/21 13:10:45 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*head;

	temp = *lst;
	head = *lst;
	while (temp != NULL)
	{
		temp = temp->next;
		del(head->content);
		free(head);
		head = temp;
	}
	*lst = NULL;
}
