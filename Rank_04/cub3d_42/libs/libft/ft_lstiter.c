/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 14:08:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 11:16:23 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstiter(t_list *lst, int (*f)(int))
{
	if (!lst)
		return (0);
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	return (0);
}
