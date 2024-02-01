/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:32:28 by mwilsch           #+#    #+#             */
/*   Updated: 2023/05/31 09:58:40 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(t_args *node)
{
	int	i;

	i = 0;
	while (node->arg[i])
	{
		node->arg[i] = ft_tolower(node->arg[i]);
		i++;
	}
	if (ft_strncmp("echo", node->arg, 4) == 0)
		return (node->type = BUILT_IN, true);
	if (ft_strncmp("pwd", node->arg, 3) == 0)
		return (node->type = BUILT_IN, true);
	if (ft_strncmp("cd", node->arg, 2) == 0)
		return (node->type = BUILT_IN, true);
	if (ft_strncmp("exit", node->arg, 4) == 0)
		return (node->type = BUILT_IN, true);
	if (ft_strncmp("env", node->arg, 3) == 0)
		return (node->type = BUILT_IN, true);
	if (ft_strncmp("unset", node->arg, 5) == 0)
		return (node->type = BUILT_IN, true);
	if (ft_strncmp("export", node->arg, 6) == 0)
		return (node->type = BUILT_IN, true);
	return (false);
}

/**
 * @brief Writes error messages
 * 
 * @param node the node of the linked list where a error occured
 * int s = start
 */
char	*cmd_err(t_args *node, t_env **env)
{
	int		s;
	char	*str;

	str = node->arg;
	if (str != NULL && str[0] == '.')
	{
		g_status = 1;
		ft_printf("minishell: %s: command not found\n", str);
		node->err_tok = NO_FILE_DIR;
		return (str);
	}
	if (ft_strchr(str, '$') && str[1] != '\0')
	{
		str = sub_env(str, get_env_len(str), env);
		if (!ft_strchr(str, '/'))
			return (resolute_cmd(node, ft_strdup(node->arg), env));
		ft_printf("minishell: %s: No such file or directory\n", str);
		return (node->err_tok = NO_FILE_DIR, str);
	}
	ft_printf("minishell: %s: command not found\n", del_quotes(str));
	g_status = 1;
	s = cnt_occur(node->arg, node->arg[0]);
	if (incl_char(node->arg[0], "><"))
		node->arg = del_substr(node->arg, s, cnt_occur(node->arg + s, ' '));
	return (node->err_tok = NO_CMD, str);
}

/**
 * @brief Preparing the command to add it to the path directory
*/
char	*prep_cmd(char *str)
{
	char	*temp;

	temp = NULL;
	if (str[0] == '.')
		return (temp);
	temp = ft_strjoin("/", str);
	free(str);
	if (!temp)
		return (NULL);
	return (temp);
}

/**
 * @brief Searching for the executable using the PATH variable
 * 
 * @param node A single node of the linked list containg a string to be resoluted
 * @param cmd A duplicate of the orginal string
 * @return cmd If command resolution was succesfull 
 * and cmd_err which returns the unchanged string
 * 
 * @note I need to also resolute in the current working directory
 */
char	*resolute_cmd(t_args *node, char *cmd, t_env **env)
{
	char	*temp;
	char	**path_2d;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (free(node->arg), cmd);
	temp = prep_cmd(cmd);
	path_2d = ft_split(getenv("PATH"), ':');
	while (path_2d && temp && path_2d[i] != NULL)
	{
		cmd = ft_strjoin(path_2d[i], temp);
		if (!cmd)
			return (free_split(path_2d), cmd);
		if (access(cmd, X_OK) == 0)
			break ;
		i++;
		free(cmd);
		cmd = NULL;
	}
	free(temp);
	free_split(path_2d);
	if (cmd == NULL || temp == NULL)
		return (free(cmd), cmd_err(node, env));
	return (free(node->arg), cmd);
}
