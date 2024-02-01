/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 14:57:41 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/22 13:08:51 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*command_path(t_data *data, char *cmd)
{
	char	*file_cmd;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (data->path_vars[i])
	{
		file_cmd = ft_strjoin(data->path_vars[i], cmd);
		if (!file_cmd)
			perror("ft_strjoin");
		if (access(file_cmd, X_OK) == 0)
		{
			return (file_cmd);
		}
		free(file_cmd);
		i++;
	}
	return (NULL);
}

char	**command_args(char *argv, char **dst)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(argv, ' ');
	if (!tmp)
		perror("ft_split");
	dst = ft_calloc((arraylen(tmp) + 1), sizeof(char *));
	if (!dst)
		error("Memory allocation error", 2);
	while (tmp[i])
	{
		dst[i] = ft_strdup(tmp[i]);
		if (!dst[i])
			perror("ft_strdup");
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (dst);
}

int	path_search(t_data *data, char **envp)
{
	data->path = NULL;
	while (!data->path)
	{
		if (ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
		{
			data->path = ft_substr(*envp, 5, ft_strlen(*envp));
			if (!data->path)
				perror("ft_substr");
			return (EXIT_SUCCESS);
		}
		envp++;
	}
	return (EXIT_FAILURE);
}

int	path_vars(t_data *data)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(data->path, ':');
	if (!tmp)
		perror("ft_split");
	data->path_vars = ft_calloc((arraylen(tmp) + 1), sizeof(char *));
	if (!data->path_vars)
		error("Memory allocation error", 2);
	while (tmp[i])
	{
		data->path_vars[i] = ft_strjoin(tmp[i], "/");
		if (!data->path_vars[i])
			perror("ft_strjoin");
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (EXIT_SUCCESS);
}

int	parse_path(t_data *data, char **argv, char **envp)
{
	data->argv = argv;
	if (path_search(data, envp))
		exit(EXIT_FAILURE);
	data->cmd1 = command_args(argv[2], data->cmd1);
	data->cmd2 = command_args(argv[3], data->cmd2);
	if (!data->cmd1 || !data->cmd2)
		return (EXIT_FAILURE);
	if (path_vars(data))
		exit (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
