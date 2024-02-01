/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 10:09:12 by dickklouwer   #+#    #+#                 */
/*   Updated: 2022/03/28 14:41:39 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (!needle)
		return ((char *)haystack);
	while (*haystack && len >= nlen && len > 0)
	{
		if (*haystack == needle[0])
		{
			if (!ft_strncmp(haystack, needle, nlen))
				return ((char *)(haystack));
		}
		haystack++;
		len--;
	}
	return (NULL);
}
