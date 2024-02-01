/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 11:58:05 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/09/26 14:58:06 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_screen(t_game *game)
{
	game->img = mlx_new_image(game->mlx, GAME_WIDHT, GAME_HEIGHT);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
		err_exit("Failed to draw screen");
	game->minimap = mlx_new_image(
			game->mlx, game->map.height * 32, game->map.width * 32);
	if (!game->minimap
		|| (mlx_image_to_window(game->mlx, game->minimap, 0, 0) < 0))
		err_exit("Failed to draw miniscreen");
	update_screen(game);
}

void	update_screen(t_game *game)
{
	draw_floor_and_cailing(game);
	draw_walls(game);
	game->map.update_screen = false;
}
