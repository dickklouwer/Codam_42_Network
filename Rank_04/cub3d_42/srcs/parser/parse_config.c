/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_config.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 13:34:14 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 12:12:17 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	prep_map_data(t_game *game)
{
	char	*temp;

	game->p.player_count = 0;
	while (get_next_line(game->map.map_fd, &temp) == 1)
	{
		if (ft_strlen(temp) > (size_t)game->map.width)
			game->map.width = ft_strlen(temp);
		map_prerequisites(game, temp, game->map.map_y);
		free(temp);
		game->map.map_y++;
	}
	game->map.map_y++;
	game->map.height = game->map.map_y;
	free(temp);
	close(game->map.map_fd);
	if (game->p.player_count != 1)
		err_exit("cub3D: More or less than 1 player ... ");
}

int	check_map_start(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strspn(line + i, "1 ") == ft_strlen(line + i))
	{
		game->map.map_y++;
		prep_map_data(game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	open_config_file(t_game *game)
{
	game->map.map_fd = open(game->config.map_path, O_RDONLY);
	if (game->map.map_fd < 0)
		err_exit("Failed to open config file ...");
}

void	read_config_file(t_game *game)
{
	char	*line;
	char	**split_line;

	while (get_next_line(game->map.map_fd, &line) == 1)
	{
		if (ft_strncmp(line, "", ft_strlen(line) != 0))
		{
			split_line = ft_split(line, ' ');
			if (!split_line)
				err_exit("Failed to split line ...");
			validate_config_variables(line, split_line);
			if (check_dup_config_vars(&game->config, line))
				err_exit("Duplicate variables in config file ...");
			set_config_variables(&game->config, line, split_line);
			game->map_exe = check_map_start(game, line);
			free_2d_array(split_line);
			if (game->map_exe)
				break ;
		}
		free(line);
		game->map.map_start++;
	}
	free(line);
	if (!game->map_exe)
		err_exit("Map not compatible ...");
}

void	parse_config(t_game *game)
{
	open_config_file(game);
	read_config_file(game);
}
