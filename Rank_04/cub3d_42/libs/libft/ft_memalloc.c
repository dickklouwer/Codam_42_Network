/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 10:36:22 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/11/02 10:37:01 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
