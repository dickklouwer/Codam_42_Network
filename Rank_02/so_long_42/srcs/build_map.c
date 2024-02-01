/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 12:31:28 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/01 10:25:35 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
**  LOADS XPM TEXTURE PATH
*/
static void	st_xpm_img(t_game *game)
{
	game->path->wall = "sprites/wall.xpm42";
	game->path->collectible = "sprites/collectible.xpm42";
	game->path->exit = "sprites/exit.xpm42";
	game->path->player = "sprites/player.xpm42";
	game->path->grass = "sprites/grass.xpm42";
}

/* 
**  CONVERTS THE XPM TEXTURE TO THE WINDOW.
*/
static int	st_load_img(t_game *game, int y, int x, char *path)
{
	game->xpm = mlx_load_xpm42(path);
	if (!game->xpm)
		exit(1);
	game->img = mlx_texture_to_image(game->mlx, &game->xpm->texture);
	if (!game->img)
		exit(1);
	if (mlx_image_to_window(game->mlx, game->img, x * PIXELS, y * PIXELS) < 0)
		exit(1);
	mlx_delete_xpm42(game->xpm);
	return (EXIT_SUCCESS);
}

/*
**  DISTRIBUTES THE RIGHT IMG ON THE VALUE OF THE Y - X AXIS.
*/
static int	st_distribute_img(t_game *game, int y, int x)
{
	if (game->map->map[y][x] == '1')
		st_load_img(game, y, x, game->path->wall);
	if (game->map->map[y][x] == 'C')
		st_load_img(game, y, x, game->path->collectible);
	if (game->map->map[y][x] == 'E')
		st_load_img(game, y, x, game->path->exit);
	if (game->map->map[y][x] == 'P')
		st_load_img(game, y, x, game->path->player);
	if (game->map->map[y][x] == '0')
		st_load_img(game, y, x, game->path->grass);
	return (EXIT_SUCCESS);
}

/* 
**  LOOPS OVER THE MAP TO DISTRIBUTE AND LOAD THE IMGS TO BUILD THE MAP.
*/
int	build_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	st_xpm_img(game);
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			st_distribute_img(game, y, x);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
