/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 11:56:30 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 12:14:24 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	flood_fill(int x, int y, t_map *map, char **map_line)
{
	if (x < 0 || y < 0 || x > map->width || y > map->height)
		return (0);
	if (map_line[y][x] == '1')
		return (0);
	if (map_line[y][x] == 'x')
		return (0);
	if (map_line[y][x] == ' ')
		return (err_exit("cub3D: Invalid character in map ..."));
	if (x == 0 || y == 0 || y == map->height - 1
		|| x == map->width - 1)
		return (err_exit("cub3D: Map not surrounded by walls ..."));
	map_line[y][x] = 'x';
	if (flood_fill(x - 1, y, map, map_line) == 1)
		return (1);
	if (flood_fill(x + 1, y, map, map_line) == 1)
		return (1);
	if (flood_fill(x, y - 1, map, map_line) == 1)
		return (1);
	if (flood_fill(x, y + 1, map, map_line) == 1)
		return (1);
	return (0);
}

int	check_dups(t_config *config)
{
	if (config->floor_color[0] == config->ceiling_color[0]
		&& config->floor_color[1] == config->ceiling_color[1]
		&& config->floor_color[2] == config->ceiling_color[2])
		return (1);
	else if (config->floor_color[0] == -1 || config->ceiling_color[0] == -1)
		return (1);
	return (0);
}

int	validate_textures(t_game *game)
{
	if (open(game->config.north_texture, O_RDONLY) < 0)
		return (EXIT_FAILURE);
	if (open(game->config.south_texture, O_RDONLY) < 0)
		return (EXIT_FAILURE);
	if (open(game->config.west_texture, O_RDONLY) < 0)
		return (EXIT_FAILURE);
	if (open(game->config.east_texture, O_RDONLY) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_variables(t_game *game)
{
	if (check_dups(&game->config))
		return (err_exit("cub3D: Colors are not valid ..."));
	if (!game->config.east_texture || !game->map.map
		|| !game->config.north_texture || !game->config.south_texture
		|| !game->config.west_texture)
		return (err_exit("cub3D: Invalid texture paths  ..."));
	if (validate_textures(game))
		return (err_exit("cub3D: Path to texture is invalid ..."));
	return (EXIT_SUCCESS);
}

int	parse_map_file(t_game *game)
{
	parse_config(game);
	parse_map(&game->map);
	validate_variables(game);
	flood_fill(game->p.start_x, game->p.start_y, &game->map, game->map.map_cpy);
	return (EXIT_SUCCESS);
}
