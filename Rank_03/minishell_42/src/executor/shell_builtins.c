/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:05:40 by tklouwer          #+#    #+#             */
/*   Updated: 2023/05/31 14:11:17 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	mini_exit(t_cmds *cmd)
{
	int	j;

	j = 0;
	if (count_args(cmd->argv) > 2)
	{
		ft_printf("exit: too many arguments\n");
		return (g_status = EXIT_FAILURE);
	}
	rl_clear_history();
	if (count_args(cmd->argv) == 1)
		exit(EXIT_SUCCESS);
	while (cmd->argv[1][j])
	{
		if (ft_isdigit(cmd->argv[1][j]) == 0)
		{
			ft_printf("exit: %s: numeric argument required\n", cmd->argv[1]);
			exit(255);
		}
		j++;
	}
	if (count_args(cmd->argv) == 2)
		exit(ft_atoi(cmd->argv[1]));
	exit(EXIT_SUCCESS);
}

int	echo(int argc, char **argv)
{
	int		i;
	bool	flag;

	i = 1;
	flag = check_flag(argv, &i);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "$?") == 0)
		{
			ft_putnbr(g_status);
			i++;
			continue ;
		}
		ft_printf("%s", argv[i]);
		if (i != argc - 1)
			ft_printf(" ");
		i++;
	}
	if (flag == true)
		ft_printf("\n");
	return (g_status = EXIT_SUCCESS);
}

int	cd(int argc, char *path, t_env *env_list)
{	
	t_env	*temp;

	if (argc == 1)
	{
		if (exisit_env(&env_list, "HOME", &temp) == -1)
			return (g_status = 1, ft_printf("cd: HOME not set\n", 2));
		return (chdir(getenv(temp->key)));
	}
	if (ft_strncmp(path, "..", 2) == 0 || ft_strncmp(path, ".", 1) == 0)
	{
		if (chdir(path) == -1)
			return (g_status = 1,
				ft_printf("cd: error changing directory: %s\n", path));
		return (g_status = EXIT_SUCCESS);
	}
	if (argc > 2)
		return (g_status = 1, ft_printf("cd: too many arguments\n", 2));
	if (access(path, F_OK) == -1)
		return (g_status = 1,
			ft_printf("cd: no such file or directory: %s\n", path));
	if (access(path, X_OK) == -1)
		return (g_status = 1, ft_printf("cd: permission denied: %s\n", path));
	chdir(path);
	return (g_status = EXIT_SUCCESS);
}

int	pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 1024);
	if (!cwd)
	{
		perror("getcwd");
		return (g_status = EXIT_FAILURE);
	}
	ft_putendl_fd(cwd, 1);
	free(cwd);
	return (g_status = EXIT_SUCCESS);
}

int	env(t_env **env_list, bool export)
{
	t_env	*env;

	env = *env_list;
	while (env)
	{
		if (export == true)
		{
			ft_printf("declare -x %s", env->key);
			if (env->value)
				ft_printf("=\"%s\"", env->value);
			ft_printf("\n");
		}
		else if (env->export_only == false)
		{
			ft_printf("%s=", env->key);
			ft_printf("%s\n", env->value);
		}
		env = env->next;
	}
	return (g_status = EXIT_SUCCESS);
}
