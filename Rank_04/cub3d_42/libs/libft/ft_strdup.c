/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 12:21:10 by dickklouwer   #+#    #+#                 */
/*   Updated: 2022/12/01 11:44:41 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = ft_strlen(s1);
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
