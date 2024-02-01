/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 17:29:35 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/11/12 11:42:51 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*substr;

	i = 0;
	if (!s)
		return (NULL);
	substr = (char *)ft_calloc(sizeof(char), len + 1);
	if (!substr)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*substr = '\0';
		return (substr);
	}
	while (s[i] && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}
