/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: verdant <verdant@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:59:02 by verdant       #+#    #+#                 */
/*   Updated: 2023/05/22 12:13:53 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args	*create_delimiter_node(t_args *temp, char *str)
{
	t_args	*new;

	new = malloc(sizeof(t_args));
	if (!new)
		return (NULL);
	new->arg = ft_calloc(sizeof(char), 2);
	if (!new->arg)
		return (NULL);
	new->arg[0] = '|';
	new->type = PIPE;
	new->err_tok = OK;
	new->next = NULL;
	new->prev = NULL;
	temp->next = new;
	new->prev = temp;
	temp = temp->next;
	del_substr(str, 0, cnt_occur(str + 1, ' ') + 1);
	return (temp);
}
