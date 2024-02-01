/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 14:00:19 by tklouwer      #+#    #+#                 */
/*   Updated: 2020/11/14 14:26:10 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*ptr;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i - 1]) != NULL && i > 1)
		i--;
	while (ft_strchr(set, *s1) != NULL && i > 0)
	{
		i--;
		s1++;
	}
	ptr = ft_substr(s1, 0, i);
	if (!ptr)
		ptr = (char *)ft_calloc(1, sizeof(char));
	return (ptr);
}
