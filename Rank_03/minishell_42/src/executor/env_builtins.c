/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_builtins.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: verdant <verdant@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:40:09 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/01 10:18:21 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	print_it(char *str)
{
	ft_printf("minishell: export: %s not a valid identifier\n", str);
	return (g_status = EXIT_FAILURE);
}

void	export_routine(char *str, t_env **env_list)
{
	t_env	*found;
	t_env	*temp;

	found = NULL;
	temp = NULL;
	if (ft_strchr(str, '=') == NULL && exisit_env(env_list, str, &temp) == -1)
	{
		add_end(env_list, str, true);
		return ;
	}
	if (temp && temp->export_only == true && !ft_strchr(str, '='))
		return ;
	exisit_env(env_list, str, &found);
	if (found == NULL)
		add_end(env_list, str, false);
	if (found != NULL)
	{
		free(found->value);
		found->value = ft_strdup(str + ft_strlen(found->key) + 1);
		if (found->export_only == true)
			found->export_only = false;
	}
}

int	export(int argc, char *av[], t_env **env_list)
{
	int		i;
	int		j;

	i = 1;
	if (argc == 1)
		return (env(env_list, true));
	while (i < argc)
	{
		if (av[i][0] == '=')
			return (print_it(av[i]));
		j = 0;
		while (av[i][j] != '\0' && av[i][j] != '=')
		{
			if (ft_isalnum(av[i][j]) == 0 || ft_isdigit(av[i][0]) == 0
					|| av[i][0] != '_')
				return (print_it(av[i]));
			j++;
		}
		export_routine(av[i], env_list);
		i++;
	}
	return (g_status = EXIT_SUCCESS);
}

void	delete_node(t_env **env_list, int position, t_env *found)
{
	t_env	*temp;
	int		i;

	i = 0;
	temp = *env_list;
	if (position != 0)
	{
		while (i < position - 1 && temp != NULL)
		{
			temp = temp->next;
			i++;
		}
		temp->next = found->next;
	}
	else
		*env_list = found->next;
	free(found->key);
	free(found->value);
	free(found);
}

/**
 * @brief 
 * 
 * 
 * 1. Check if the variable exists in the environment list
 * 2. If it does, figure out the position of the node in the list
 * 3. Delete the node
 */
int	unset(int argc, char *argv[], t_env **env_list)
{
	t_env	*found;
	int		position;

	if (argc == 1)
		return (g_status = EXIT_SUCCESS);
	while (argc > 1)
	{
		if (ft_strchr(argv[argc - 1], '=') != NULL)
		{
			ft_printf("minishell: unset: identifier unvalid\n", argv[argc - 1]);
			return (g_status = EXIT_FAILURE);
		}
		position = exisit_env(env_list, argv[argc - 1], &found);
		if (position == -1)
		{
			return (g_status = EXIT_SUCCESS);
		}
		delete_node(env_list, position, found);
		argc--;
	}
	return (g_status = EXIT_SUCCESS);
}
