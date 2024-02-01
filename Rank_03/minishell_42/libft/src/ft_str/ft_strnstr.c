/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:25:01 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/11 19:58:58 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle[0])
		{
			k = 0;
			while (needle[k] && haystack[i] == needle[k] && i < n)
			{
				i++;
				k++;
			}
			if (needle[k] == '\0')
				return ((char *)haystack + i - k);
			else
				i = i - k;
		}
		i++;
	}
	return (NULL);
}
