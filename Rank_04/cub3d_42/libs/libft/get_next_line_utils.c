/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:28:15 by dickklouwer   #+#    #+#                 */
/*   Updated: 2022/11/30 14:42:18 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_memcccpy(char *dst, char *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)(dst);
	s = (unsigned char *)(src);
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
		{
			d[i] = '\0';
			return (dst);
		}
		i++;
	}
	return (dst);
}

char	*ft_strchr_g(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strdup_g(const char *s1)
{
	size_t	i;
	char	*str;

	i = ft_strlen_g(s1);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen_g(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
