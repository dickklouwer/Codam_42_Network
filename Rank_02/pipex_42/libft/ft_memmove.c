/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 08:11:40 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/11/10 11:09:10 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (s < d)
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
