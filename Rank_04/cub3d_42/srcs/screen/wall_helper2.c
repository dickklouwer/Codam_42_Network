/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_helper2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 14:19:03 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/09/26 14:59:00 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_colour_from_pixel(u_int8_t *pixel)
{
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

void	load_current_texture(t_game *game)
{
	if (game->p.side == 0)
	{
		if (game->p.step_x > 0)
			game->p.texture = game->p.texture_e;
		else
			game->p.texture = game->p.texture_w;
	}
	else
	{
		if (game->p.step_y > 0)
			game->p.texture = game->p.texture_s;
		else
			game->p.texture = game->p.texture_n;
	}
}

void	calculate_texture_position(t_game *game)
{
	load_current_texture(game);
	if (game->p.side == 0)
	{
		game->p.wall_x = game->p.pos_y
			+ game->p.perp_wal_dist * game->p.ray_dir_y;
	}
	else
	{
		game->p.wall_x = game->p.pos_x
			+ game->p.perp_wal_dist * game->p.ray_dir_x;
	}
	game->p.wall_x -= floor(game->p.wall_x);
	game->p.tex_x = (int)(game->p.wall_x * (double)(game->p.texture->width));
	if (game->p.side == 0 && game->p.ray_dir_x > 0)
		game->p.tex_x = game->p.texture->width - game->p.tex_x - 1;
	if (game->p.side == 1 && game->p.ray_dir_y < 0)
		game->p.tex_x = game->p.texture->width - game->p.tex_x - 1;
	game->p.step = 1.0 * game->p.texture->height / game->p.line_height;
	game->p.tex_pos = (game->p.line_start_y - game->p.pitch - GAME_HEIGHT
			/ 2 + game->p.line_height / 2) * game->p.step;
}

void	draw_vertical_line(t_game *game, int x)
{
	int	y;

	y = game->p.line_start_y;
	while (y < game->p.line_stop_y)
	{
		game->p.tex_y = (int)game->p.tex_pos & (game->p.texture->height - 1);
		game->p.tex_pos += game->p.step;
		game->p.color = get_colour_from_pixel(game->p.texture->pixels
				+ (game->p.texture->height * game->p.tex_y + game->p.tex_x)
				* game->p.texture_n->bytes_per_pixel);
		mlx_put_pixel(game->img, x, y, game->p.color);
		y++;
	}
}
