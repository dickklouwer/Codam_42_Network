/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:01:27 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/10/29 16:44:54 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		k;
	size_t		i;

	k = 0;
	i = 0;
	while (i < dstsize && dst[i])
		i++;
	while (src[k] && (i + k + 1) < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i < dstsize)
		dst[i + k] = '\0';
	return (size_t)(i + ft_strlen(src));
}
