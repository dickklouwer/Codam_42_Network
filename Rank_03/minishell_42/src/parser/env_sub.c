/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:33:01 by mwilsch           #+#    #+#             */
/*   Updated: 2023/06/01 08:59:20 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exisit_env(t_env **env_list, char *str, t_env **found)
{
	char	**key;
	t_env	*temp;
	int		position;

	if (env_list == NULL || *env_list == NULL || !str[0])
		return (-1);
	if (found != NULL)
		*found = NULL;
	key = ft_split(str, '=');
	temp = *env_list;
	position = 0;
	while (temp != NULL)
	{
		if (temp->key != NULL && ft_strcmp(key[0], temp->key) == 0)
		{
			*found = temp;
			free_split(key);
			return (position);
		}
		temp = temp->next;
		position++;
	}
	free_split(key);
	return (-1);
}

/**
 * @brief counts the length of the unsubsituted env_var
 * 
 * @return e.G $HOME it returns 4 (4 chars after the $)
*/
int	get_env_len(char *str)
{
	const int	start = ft_strclen(str, '$') + 1;
	int			len;

	len = start;
	while (str[len] && !incl_char(str[len], " <>\""))
		len++;
	return (len - start);
}

/**
 * @brief Substitutes the environment variable inside of of the string
 * 
 * @param str String to be subsitutued. str gets freed! Do I want that?
 * @param env_len The length of the unsubsituted env_var
 * 
 * @note First it copies all chars before the $. Then it 
 * concatenates the env_var.
 * Finally it copies to the rest of the string
 * 
 * @note I'm missing the deletion of env_var if env_var does not exsit
*/
char	*sub_env(char *str, int env_len, t_env **env_l)
{
	const int	start = ft_strclen(str, '$') + 1;
	t_env		*e;
	char		*new;
	int			len;

	if (!str)
		return (NULL);
	if (ft_strcmp(str, "$?") == 0)
		return (str);
	new = ft_substr(str, start, env_len);
	exisit_env(env_l, new, &e);
	free(new);
	if (!e)
		return (del_substr(str, start - 1, env_len + 1));
	len = (ft_strlen(str) + ft_strlen(e->value)) - (env_len + 1);
	new = ft_calloc(sizeof(char), (len + 1));
	if (!new)
		return (NULL);
	len = ft_strlcpy(new, str, ft_strclen(str, '$') + 1);
	if (e->value)
		len = ft_strlcat(new, e->value, len + ft_strlen(e->value) + 1);
	env_len += start;
	while (str[env_len] && env_len < len)
		new[len++] = str[env_len++];
	return (free(str), new);
}
