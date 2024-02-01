/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 11:15:07 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/09/22 16:48:05 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;

	while (*lst)
	{
		current = *lst;
		*lst = current->next;
		ft_lstdelone(current, del);
	}
	*lst = NULL;
}
