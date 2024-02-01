/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 11:25:55 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/11/18 12:30:09 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**free_arrays(char **arrays, int i)
{
	while (i >= 0)
	{
		free(arrays[i]);
		i--;
	}
	free(arrays);
	return (NULL);
}

static unsigned int		wordcount(char const *str, char c)
{
	unsigned int	counter;
	unsigned int	i;

	i = 1;
	if (!ft_strlen(str))
		return (0);
	else if (str[0] == c)
		counter = 0;
	else
		counter = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			counter++;
		i++;
	}
	return (counter);
}

static char				**make_arr(int i, char const *s, char c)
{
	int		j;
	int		x;
	int		k;
	char	**arrays;

	j = 0;
	x = 0;
	arrays = (char **)ft_calloc(sizeof(char*), i + 1);
	if (!arrays)
		return (NULL);
	while (s[j] && x < i)
	{
		while (s[j] == c && s[j])
			j++;
		k = j;
		while (s[j] != c && s[j])
			j++;
		arrays[x] = ft_substr(s, k, j - k);
		if (!arrays[x])
			return (free_arrays(arrays, i));
		x++;
	}
	return (arrays);
}

char					**ft_split(char const *s, char c)
{
	char	**arrays;
	int		i;

	if (!s)
		return (NULL);
	i = wordcount(s, c);
	arrays = make_arr(i, s, c);
	return (arrays);
}
