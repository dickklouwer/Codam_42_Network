/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 15:55:24 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/01 13:50:47 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
** Checks if the map is surrounded with walls.
** If not, the function exits with an error message.
*/
static int	st_wall_check(t_map *map, char *line, int y)
{
	int	i;

	i = 0;
	if (y == 0 || y == map->height - 1)
	{
		while (line[i])
		{
			if (line[i] != '1')
				error("INVALID BORDERS");
			i++;
		}
	}
	else if (line[0] != '1' || line[map->width - 1] != '1')
		error("INVALID BORDERS");
	return (EXIT_SUCCESS);
}

/* 
** Scans the map and stores the data.
** If the data is not right, the function exits with an error message.
*/
static int	st_map_data(t_game *game, char *line, int y)
{
	int	i;

	i = 0;
	game->map->width = ft_strlen(line);
	while (line[i])
	{
		if ((line[i] != 'P') && (line[i] != 'E') && (line[i] != 'C')
			&& (line[i] != '0') && (line[i] != '1'))
			error("INVALID MAP TILE");
		if (line[i] == 'P')
		{
			game->player.x = i;
			game->player.y = y;
			game->map->inv_start++;
		}
		if (line[i] == 'E')
			game->map->inv_exit++;
		i++;
	}
	if (i != game->map->width)
		error("INVALID WIDTH");
	return (EXIT_SUCCESS);
}

/*  
** Checks the mandatory data in the map.
** If the data is not right, the function exits with an error message.
*/
int	st_check_data(t_game *game, char **map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = (char **)ft_calloc(game->map->height + 1, sizeof(char *));
	if (!map_cpy)
		return (EXIT_FAILURE);
	while (i < game->map->height)
	{
		map_cpy[i] = ft_strdup(map[i]);
		i++;
	}
	flood_fill(game->player.x, game->player.y, game, map_cpy);
	if (game->map->exit != 1 || game->map->start != 1)
		error("NO VALID START/EXIT\nGAME CLOSED");
	if (game->map->coll < 1)
		error("NO POKÉ BALLS");
	if (game->map->width > 41)
		error("WINDOW WIDTH EXCEEDED");
	free_arr(map_cpy, i);
	if (game->map->inv_exit > 0 || game->map->exit != 1)
		error("DUPLICATE EXIT");
	if (game->map->inv_start > 0 || game->map->start != 1)
		error("DUPLICATE STARTING POSITION");
	return (EXIT_SUCCESS);
}

/* 
** Reads the map for the first time to store the Height & Width.
*/
static int	st_pre_check(t_game *game, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("COULDN'T READ MAP");
	while (get_next_line(fd, &line) == 1)
	{
		st_map_data(game, line, i);
		free(line);
		i++;
	}
	free(line);
	game->map->height = i + 1;
	close(fd);
	return (EXIT_SUCCESS);
}

/* 
** Parses the map with help of the above functions.
** If something is invalid, the program will exit.
*/
int	parse_map(t_game *game, char *file)
{
	int	fd;
	int	i;

	i = 0;
	if (st_pre_check(game, file))
		return (EXIT_FAILURE);
	game->map->map = (char **)ft_calloc(game->map->height + 1, sizeof(char *));
	if (!game->map->map)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	get_next_line(fd, &game->map->map[i]);
	while (i < game->map->height)
	{
		st_wall_check(game->map, game->map->map[i], i);
		i++;
		get_next_line(fd, &game->map->map[i]);
	}
	close(fd);
	return (st_check_data(game, game->map->map));
}
