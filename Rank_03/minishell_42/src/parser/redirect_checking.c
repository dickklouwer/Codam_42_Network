/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:31:04 by mwilsch           #+#    #+#             */
/*   Updated: 2023/05/31 09:40:01 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief parse error messages
 * 
 * @param err The type of error
*/
int	err_msg(t_err_tok err)
{
	if (err == NO_FILE_DIR)
		return (ft_printf("minishell: : No such file or directory\n"));
	if (err == TO_MANY)
		return (ft_printf("minishell: To many consecutive redirects\n"));
	if (err == NO_ALNUM_BETWEEN)
		return (ft_printf("minishell: No alnum value between redirect\n"));
	if (err == NEWLINE_ERR)
		return (ft_printf("minishell: No alnum value after redirect\n"));
	return (1);
}

int	env_var_case(char *str, int env_len, int cnt, t_env **env)
{
	char	*env_var;
	bool	flag;

	flag = false;
	env_var = ft_substr(str, ft_strclen(str, '$'), env_len);
	env_var = sub_env(env_var, env_len - 1, env);
	if (!env_var)
		return (1);
	if (env_var[0] != '/' && !ft_strchr(str, '\"'))
		flag = ft_printf("minishell: %s: ambiguous redirect\n",
				str + ft_strclen(str, '$'));
	if (!ft_strchr(str, '\"') && access(env_var, F_OK) == 0)
		flag = ft_printf("minishell: %s: Is a directory\n", env_var);
	free(env_var);
	if (flag == false)
	{
		while (str[cnt] && str[cnt] == ' ')
			cnt++;
		str = del_substr(del_quotes(str), 0, cnt);
		str = sub_env(ft_strdup(str), env_len - 1, env);
		if (access(str, W_OK))
			ft_printf("minishell: %s: permission denied\n", str);
	}
	return (ENV_REDIRECT_ERR);
}

/**
 * @brief Checking the syntax of the redirects
 * 
 * @note Possible errors
 * 0. To many: >>> or <<< (3+ redirects)
 * 1. Ambigous Redirect: >$HOE
 * 2. No alnum value in between redirects: >   >file
 * 3. No alnum value after redirect: cmd >
 * 4. Special case: <> is valid but I will error
 * 5. redirect: >"" --> No such file or directory (Not implemented)
*/
int	c_red(char *str, int cnt, t_args *node, t_env **env)
{
	int	i;

	if (!str)
		return (1);
	i = cnt - 1;
	if (incl_char(str[cnt], "\'\"") && incl_char(str[cnt + 1], "\'\""))
		return (err_msg(NO_FILE_DIR));
	if (cnt > 2)
		return (err_msg(TO_MANY));
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			break ;
		i++;
		if (incl_char(str[i], ">|<"))
			return (err_msg(NO_ALNUM_BETWEEN));
		if (str[i] == '\0')
			return (err_msg(NEWLINE_ERR));
	}
	if (!ft_strchr(str, '\'') && ft_strchr(str, '$'))
		node->err_tok = env_var_case(str, get_env_len(str) + 1, cnt, env);
	str = del_substr(str, cnt, cnt_occur(str + cnt, ' '));
	return (0);
}
