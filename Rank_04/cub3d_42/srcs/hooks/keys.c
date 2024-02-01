/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 13:08:32 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/08/18 15:05:22 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_donw_w(t_game *game)
{
	if (game->map.map[(int)game->p.pos_y][(int)(game->p.pos_x + game->p.dir_x \
		* game->p.move_speed * game->p.space)] != '1')
		game->p.pos_x += (game->p.dir_x * game->p.move_speed);
	if (game->map.map[(int)(game->p.pos_y + game->p.dir_y * game->p.move_speed \
		* game->p.space)][(int)game->p.pos_x] != '1')
		game->p.pos_y += (game->p.dir_y * game->p.move_speed);
	game->map.update_screen = true;
}

void	key_down_s(t_game *game)
{
	if (game->map.map[(int)game->p.pos_y][(int)(game->p.pos_x - game->p.dir_x \
		* game->p.move_speed * game->p.space)] != '1')
		game->p.pos_x -= (game->p.dir_x * game->p.move_speed);
	if (game->map.map[(int)(game->p.pos_y - game->p.dir_y * game->p.move_speed \
		* game->p.space)][(int)game->p.pos_x] != '1')
		game->p.pos_y -= (game->p.dir_y * game->p.move_speed);
	game->map.update_screen = true;
}

void	key_down_a(t_game *game)
{
	if (game->map.map[(int)(game->p.pos_y - game->p.dir_x * game->p.move_speed \
		* game->p.space)][(int)game->p.pos_x] != '1')
		game->p.pos_y -= (game->p.dir_x * game->p.move_speed);
	if (game->map.map[(int)game->p.pos_y][(int)(game->p.pos_x + game->p.dir_y \
		* game->p.move_speed * game->p.space)] != '1')
		game->p.pos_x += (game->p.dir_y * game->p.move_speed);
	game->map.update_screen = true;
}

void	key_down_d(t_game *game)
{
	if (game->map.map[(int)(game->p.pos_y + game->p.dir_x * game->p.move_speed \
		* game->p.space)][(int)game->p.pos_x] != '1')
		game->p.pos_y += (game->p.dir_x * game->p.move_speed);
	if (game->map.map[(int)game->p.pos_y][(int)(game->p.pos_x - game->p.dir_y \
		* game->p.move_speed * game->p.space)] != '1')
		game->p.pos_x -= (game->p.dir_y * game->p.move_speed);
	game->map.update_screen = true;
}

void	key_pressed(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		key_donw_w(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		key_down_s(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		key_down_d(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		key_down_a(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		key_down_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		key_down_right(game);
	if (game->map.update_screen)
		update_screen(game);
}
