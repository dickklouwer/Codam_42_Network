/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_keys.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 14:26:08 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/08/18 14:26:19 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_down_left(t_game *game)
{
	game->p.old_dir_x = game->p.dir_x;
	game->p.dir_x = (game->p.dir_x * cos(-game->p.rotate_speed)) \
		- (game->p.dir_y * sin(-game->p.rotate_speed));
	game->p.dir_y = (game->p.old_dir_x * sin(-game->p.rotate_speed)) \
		+ (game->p.dir_y * cos(-game->p.rotate_speed));
	game->p.old_plane_x = game->p.plane_x;
	game->p.plane_x = (game->p.plane_x * cos(-game->p.rotate_speed)) \
		- (game->p.plane_y * sin(-game->p.rotate_speed));
	game->p.plane_y = (game->p.old_plane_x * sin(-game->p.rotate_speed)) \
		+ (game->p.plane_y * cos(-game->p.rotate_speed));
	game->map.update_screen = true;
}

void	key_down_right(t_game *game)
{
	game->p.old_dir_x = game->p.dir_x;
	game->p.dir_x = (game->p.dir_x * cos(game->p.rotate_speed)) \
		- (game->p.dir_y * sin(game->p.rotate_speed));
	game->p.dir_y = (game->p.old_dir_x * sin(game->p.rotate_speed)) \
		+ (game->p.dir_y * cos(game->p.rotate_speed));
	game->p.old_plane_x = game->p.plane_x;
	game->p.plane_x = (game->p.plane_x * cos(game->p.rotate_speed)) \
		- (game->p.plane_y * sin(game->p.rotate_speed));
	game->p.plane_y = (game->p.old_plane_x * sin(game->p.rotate_speed)) \
		+ (game->p.plane_y * cos(game->p.rotate_speed));
	game->map.update_screen = true;
}
