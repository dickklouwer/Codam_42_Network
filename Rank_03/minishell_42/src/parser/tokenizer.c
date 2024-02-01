/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:12:14 by mwilsch           #+#    #+#             */
/*   Updated: 2023/06/01 09:01:31 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Cutting out the token out of the input string
 * 
 * @note I add 2 to len because of the quotes
*/
char	*get_tok(char *input, int start, t_type_tok type)
{
	char	*res;
	int		len;

	len = start;
	while (type == OPERATOR && input[len] && incl_char(input[len], " >|<"))
		len++;
	while (type != QUOTE_ARG && input[len] && !incl_char(input[len], " >|<"))
	{
		if (incl_char(input[len], "\'\""))
			len += cnt_len_between(input, input[len], len + 1) + 1;
		len++;
	}
	len -= start;
	if (type == QUOTE_ARG)
	{
		len = cnt_len_between(input, input[start], start + 1) + 2;
		while (input[len] && !incl_char(input[len], " >|<"))
			len++;
	}
	res = ft_substr(input, start, len);
	input = del_substr(input, start, len);
	if (!res || !input)
		return (NULL);
	return (res);
}

t_args	*create_node(char *str, t_type_tok type)
{
	t_args	*new;

	new = malloc(sizeof(t_args));
	if (!new)
		return (NULL);
	new->arg = str;
	new->err_tok = OK;
	new->next = NULL;
	new->prev = NULL;
	new->type = type;
	if (type == OPERATOR && incl_char(str[0], "|."))
	{
		new->type = CMD;
		if (ft_strchr(str, '>') || ft_strchr(str, '<'))
			new->type = REDIR;
	}
	if (incl_char(str[0], "><") && type == OPERATOR)
		new->type = REDIR;
	return (new);
}

/**
 * @brief Creating a node & adding it to the list
 * @param str a single token from the input string
 * @param type defines the token's meaning
 * 
 * @note Both creates the first node and adds nodes to the first
*/
int	add_tok(char *str, t_args **head, t_type_tok type)
{
	t_args	*new;
	t_args	*temp;

	temp = *head;
	new = create_node(str, type);
	if (!new)
		return (-1);
	if (!temp)
	{
		*head = new;
		if (type == ARG || type == QUOTE_ARG)
			new->type = CMD;
		if (type == QUOTE_ARG)
			new->arg = del_quotes(new->arg);
		return (0);
	}
	while (temp->next != NULL)
		temp = temp->next;
	if (str[0] == '|')
		temp = create_delimiter_node(temp, str);
	if (temp && type == ARG && temp->type == REDIR)
		new->type = CMD;
	temp->next = new;
	new->prev = temp;
	return (0);
}

/**
 * @brief Adds all token to a linked list
 * 
 * @param input Command Line Input
*/
t_args	*create_tok_list(char *input, t_args *head)
{
	int	i;

	i = 0;
	while (ft_strlen(input) != 0 && input[i])
	{
		if (incl_char(input[i], ">|<"))
			i = add_tok(get_tok(input, i, OPERATOR), &head, OPERATOR);
		if (ft_isalnum(input[i]) || incl_char(input[i], ".$-/_+-*="))
			i = add_tok(get_tok(input, i, ARG), &head, ARG);
		if (incl_char(input[i], "\'\""))
			i = add_tok(get_tok(input, i, QUOTE_ARG), &head, QUOTE_ARG);
		if (i == -1)
			return (NULL);
		i++;
	}
	return (head);
}

t_args	*process_tok(t_args *head, char *input, t_env **env)
{
	t_args	*node;

	node = head;
	while (node != NULL)
	{
		if (node->type == CMD && !is_builtin(node))
			node->arg = resolute_cmd(node, ft_strdup(node->arg), env);
		if (node->type == REDIR && c_red(node->arg,
				cnt_occur(node->arg, node->arg[0]), node, env) > 0)
			return (head->type = REPROMPT, free_list(head), free(input), NULL);
		if (ft_strcmp(node->arg, "$?") == 0)
		{
			free(node->arg);
			node->arg = ft_itoa(g_status);
		}
		if (ft_strchr(node->arg, '$') && node->arg[0] != '\'')
		{
			while (ft_strchr(node->arg, '$') && node->type != REDIR
				&& node->arg[1] != '\0')
				node->arg = sub_env(node->arg, get_env_len(node->arg), env);
		}
		del_quotes(node->arg);
		node = node->next;
	}
	return (head);
}
