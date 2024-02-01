/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:26:37 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/21 14:07:43 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (!ptr)
	{
		*lst = new;
		return ;
	}
	while (ptr && ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

// pointer lst or *lst is the head of the list
// new is the node which needs to be added 
	// so node has content: sth and new.next = NULL
// Delcare t_list ptr to traverse
// SEt ptr and head the same
// Traverse until ptr is null
// then set ptr to new