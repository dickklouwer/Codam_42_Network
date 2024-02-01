/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mwilsch <mwilsch@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 17:54:34 by mwilsch       #+#    #+#                 */
/*   Updated: 2023/04/24 13:58:51 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	count_words(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != c)
		{
			cnt++;
			while (str[i] != c && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (cnt);
}

int	count_chars(char *str, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		i++;
		cnt++;
	}
	return (cnt);
}

char	*store_wrd(char *str, char c)
{
	const int	word_len = count_chars(str, c);
	char		*temp;
	int			i;
	int			k;

	i = 0;
	k = 0;
	temp = malloc(sizeof(char) * (word_len + 1));
	if (!temp)
		return (NULL);
	temp[word_len] = '\0';
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && k < word_len)
		temp[k++] = str[i++];
	return (temp);
}

void	trim_string(char *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] && str[i] == c)
		i++;
	i += count_chars(str, c);
	while (str[i])
		str[k++] = str[i++];
	str[k] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		wrd_cnt;
	char	**s_arr;
	char	*str;
	int		i;

	i = 0;
	wrd_cnt = count_words((char *)s, c);
	str = ft_strdup(s);
	s_arr = malloc(sizeof(char *) * (wrd_cnt + 1));
	if (!s_arr || wrd_cnt == -1)
		return (free(s_arr), NULL);
	s_arr[wrd_cnt] = NULL;
	while (i < wrd_cnt)
	{
		s_arr[i] = store_wrd(str, c);
		trim_string(str, c);
		i++;
	}
	return (free(str), s_arr);
}
