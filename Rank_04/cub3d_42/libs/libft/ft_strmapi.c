/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:27:29 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/11/08 19:02:16 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}
