/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 11:56:26 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/08/18 14:31:41 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_orientation_ns(t_game *game)
{
	if (game->p.orientation == 'N')
	{
		game->p.dir_x = 0;
		game->p.dir_y = -1;
		game->p.plane_x = 0.66;
		game->p.plane_y = 0;
	}
	if (game->p.orientation == 'S')
	{
		game->p.dir_x = 0;
		game->p.dir_y = 1;
		game->p.plane_x = -0.66;
		game->p.plane_y = 0;
	}
}

void	init_orientation_ew(t_game *game)
{
	if (game->p.orientation == 'E')
	{
		game->p.dir_x = 1;
		game->p.dir_y = 0;
		game->p.plane_x = 0;
		game->p.plane_y = 0.66;
	}
	if (game->p.orientation == 'W')
	{
		game->p.dir_x = -1;
		game->p.dir_y = 0;
		game->p.plane_x = 0;
		game->p.plane_y = -0.66;
	}
}

void	init_position(t_game *game)
{
	game->p.pos_x = game->p.start_x - 0.5;
	game->p.pos_y = game->p.start_y - 0.5;
	game->p.pitch = 100;
}

void	init_movement(t_game *game)
{
	game->p.move_speed = 0.1;
	game->p.rotate_speed = 0.07;
	game->p.space = 3.0;
}

void	init_player(t_game *game)
{
	init_position(game);
	init_orientation_ns(game);
	init_orientation_ew(game);
	init_movement(game);
}
