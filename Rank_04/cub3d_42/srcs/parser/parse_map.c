/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 11:44:19 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/08/21 19:43:12 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	map_copy(t_map *map)
{
	int	i;

	i = 0;
	map->map_cpy = (char **)ft_calloc(map->map_y, sizeof(char *));
	if (!map->map_cpy)
		err_exit("Memory allocation failed");
	while (i < map->map_y)
	{
		map->map_cpy[i] = ft_strdup(map->map[i]);
		if (!map->map_cpy[i])
			err_exit("Failed to copy map");
		i++;
	}
}

void	read_till_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	while (i < map->map_start)
	{
		get_next_line(map->map_fd, &line);
		free(line);
		i++;
	}
}

void	parse_map(t_map *map)
{
	int		i;

	i = 0;
	map->map_fd = open(map->path, O_RDONLY);
	if (map->map_fd < 0)
		err_exit("Failed to open map");
	map->map = (char **)ft_calloc(map->map_y + 1, sizeof(char *));
	if (!map->map)
		err_exit("Memory allocation failed");
	read_till_map(map);
	while (i < map->map_y)
	{
		get_next_line(map->map_fd, &map->map[i]);
		i++;
	}
	map_copy(map);
	close(map->map_fd);
}
