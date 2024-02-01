/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:25:25 by tklouwer          #+#    #+#             */
/*   Updated: 2023/05/30 13:11:46 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize_shell(t_env *env)
{
	size_t	n;

	n = 0;
	while (env != NULL)
	{
		env = env->next;
		n++;
	}
	return (n);
}

/**
 * @brief Deletes a substr from a str
 * 
 * @param start The starting index of str to delete from
 * @param len The amount of chars to delete
 * 
*/
char	*del_substr(char *str, int start, int len)
{
	int	copy_from;

	if (!str)
		return (NULL);
	if (len == 0 || len > ft_strlen(str))
		return (str);
	if (str[len] == '\0')
	{
		str[start] = '\0';
		return (str);
	}
	copy_from = start + len;
	while (str[copy_from])
		str[start++] = str[copy_from++];
	str[start] = '\0';
	return (str);
}

bool	is_valid_pipe(char *input)
{
	int	i;

	if (ft_strchr(input, '|') == NULL)
		return (true);
	i = ft_strclen(input, '|');
	while (input[i])
	{
		if (ft_isalnum(input[i]) || incl_char(input[i], "><"))
			return (true);
		i++;
	}
	return (false);
}
