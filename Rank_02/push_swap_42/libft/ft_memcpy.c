/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/25 11:04:32 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/11/14 13:37:13 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)(dst);
	s = (unsigned char *)(src);
	if (!d && !s)
		return (NULL);
	else
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (void *)(dst);
}
