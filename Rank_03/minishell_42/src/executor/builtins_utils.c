/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:38:52 by dickklouwer       #+#    #+#             */
/*   Updated: 2023/06/01 08:45:50 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	exec_builtin(char *func, int argc, char **argv, t_env **env_list)
{
	if (ft_strcmp("echo", func) == 0)
		echo(argc, argv);
	if (ft_strcmp("cd", func) == 0)
		cd(argc, argv[1], *env_list);
	if (ft_strcmp("pwd", func) == 0)
		pwd();
	if (ft_strcmp("env", func) == 0)
		env(env_list, false);
	if (ft_strcmp("export", func) == 0)
		export(argc, argv, env_list);
	if (ft_strcmp("unset", func) == 0)
		unset(argc, argv, env_list);
	return (EXIT_SUCCESS);
}

bool	check_flag(char **argv, int *i)
{
	int		idx;
	int		idx_2;
	bool	flag;

	idx = 1;
	if (!argv[1])
		return (true);
	flag = true;
	while (argv[idx] != NULL)
	{
		if (argv[idx][0] != '-' || argv[idx][1] == '\0')
			break ;
		idx_2 = 0;
		while (argv[idx][idx_2] && incl_char(argv[idx][idx_2], "-n"))
			idx_2++;
		if (argv[idx][idx_2] == '\0')
		{
			(*i)++;
			flag = false;
		}
		else
			break ;
		idx++;
	}
	return (flag);
}
