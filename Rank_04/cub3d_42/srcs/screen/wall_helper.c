/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_helper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 14:17:15 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/08/18 14:17:27 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player_position(t_game *game)
{
	game->p.map_x = (int)game->p.pos_x;
	game->p.map_y = (int)game->p.pos_y;
}

void	calculate_delta_dis(t_game *game)
{
	if (game->p.ray_dir_x == 0)
		game->p.delta_dist_x = INFINITY;
	else
		game->p.delta_dist_x = fabs(1 / game->p.ray_dir_x);
	if (game->p.ray_dir_y == 0)
		game->p.delta_dist_y = INFINITY;
	else
		game->p.delta_dist_y = fabs(1 / game->p.ray_dir_y);
}

void	calculate_side_dis_x(t_game *game)
{
	if (game->p.ray_dir_x < 0)
	{
		game->p.step_x = -1;
		game->p.side_dist_x = (game->p.pos_x - game->p.map_x) \
			* game->p.delta_dist_x;
	}
	else
	{
		game->p.step_x = 1;
		game->p.side_dist_x = (game->p.map_x + 1.0 - game->p.pos_x) \
			* game->p.delta_dist_x;
	}
}

void	calculate_side_dis_y(t_game *game)
{
	if (game->p.ray_dir_y < 0)
	{
		game->p.step_y = -1;
		game->p.side_dist_y = (game->p.pos_y - game->p.map_y) \
			* game->p.delta_dist_y;
	}
	else
	{
		game->p.step_y = 1;
		game->p.side_dist_y = (game->p.map_y + 1.0 - game->p.pos_y) \
			* game->p.delta_dist_y;
	}
}

void	calculate_step(t_game *game)
{
	get_player_position(game);
	calculate_delta_dis(game);
	calculate_side_dis_x(game);
	calculate_side_dis_y(game);
}
