/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 06:20:29 by dickklouwer   #+#    #+#                 */
/*   Updated: 2022/03/28 14:41:04 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*p;

	p = NULL;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
		{
			p = (char *)s + i;
			return ((char *)(p));
		}
		i--;
	}
	return (NULL);
}
