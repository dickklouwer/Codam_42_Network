/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 09:01:37 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/01 13:48:56 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
** Registers the data of the map.
*/
int	map_data(int c, t_game *game)
{
	if (c == 'E')
	{
		game->map->exit++;
		game->map->inv_exit--;
	}
	if (c == 'P')
	{
		game->map->start++;
		game->map->inv_start--;
	}
	if (c == 'C')
		game->map->coll++;
	return (0);
}

/* 
** Floods the map and checks if there's a valid path inside the game.
*/
int	flood_fill(int x, int y, t_game *game, char **map)
{
	if (x < 0 || y < 0 || x > game->map->width || y > game->map->height)
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'x')
		return (0);
	map_data(map[y][x], game);
	if (x == 0 || y == 0 || y == game->map->height - 1
		|| x == game->map->width - 1)
		return (error("MAP NOT SUROUNDED BY WALLS."));
	map[y][x] = 'x';
	if (flood_fill(x - 1, y, game, map) == 1)
		return (1);
	if (flood_fill(x + 1, y, game, map) == 1)
		return (1);
	if (flood_fill(x, y - 1, game, map) == 1)
		return (1);
	if (flood_fill(x, y + 1, game, map) == 1)
		return (1);
	return (0);
}
