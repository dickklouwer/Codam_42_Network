/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 14:11:17 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/08/18 14:54:40 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_position_and_direction(t_game *game, int x)
{
	game->p.camera_x = (2 * x / (double)GAME_WIDHT) - 1;
	game->p.ray_dir_x = game->p.dir_x + (game->p.plane_x * game->p.camera_x);
	game->p.ray_dir_y = game->p.dir_y + (game->p.plane_y * game->p.camera_x);
}

void	digital_differential_analysis(t_game *game)
{
	game->p.hit = 0;
	while (game->p.hit == 0)
	{
		if (game->p.side_dist_x < game->p.side_dist_y)
		{
			game->p.side_dist_x += game->p.delta_dist_x;
			game->p.map_x += game->p.step_x;
			game->p.side = 0;
		}
		else
		{
			game->p.side_dist_y += game->p.delta_dist_y;
			game->p.map_y += game->p.step_y;
			game->p.side = 1;
		}
		if (game->map.map[game->p.map_y][game->p.map_x] == '1')
			game->p.hit = 1;
	}
}

void	calculate_distance(t_game *game)
{
	if (game->p.side == 0)
		game->p.perp_wal_dist = game->p.side_dist_x - game->p.delta_dist_x;
	else
		game->p.perp_wal_dist = game->p.side_dist_y - game->p.delta_dist_y;
}

void	calculate_vertical_line(t_game *game)
{
	game->p.line_height = (int)(GAME_HEIGHT / game->p.perp_wal_dist);
	game->p.line_start_y = (GAME_HEIGHT / 2) - (game->p.line_height / 2) \
		+ game->p.pitch;
	game->p.line_stop_y = (GAME_HEIGHT / 2) + (game->p.line_height / 2) \
		+ game->p.pitch;
	if (game->p.line_start_y < 0)
		game->p.line_start_y = 0;
	if (game->p.line_stop_y >= GAME_HEIGHT)
		game->p.line_stop_y = GAME_HEIGHT - 1;
}

void	draw_walls(t_game *game)
{
	int	x;

	x = 0;
	while (x < GAME_WIDHT)
	{
		calculate_ray_position_and_direction(game, x);
		calculate_step(game);
		digital_differential_analysis(game);
		calculate_distance(game);
		calculate_vertical_line(game);
		calculate_texture_position(game);
		draw_vertical_line(game, x);
		x++;
	}
}
