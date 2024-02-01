/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 11:54:43 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/08/21 13:08:33 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	delete_textures(t_game *game)
{
	mlx_delete_texture(game->p.texture_n);
	mlx_delete_texture(game->p.texture_s);
	mlx_delete_texture(game->p.texture_w);
	mlx_delete_texture(game->p.texture_e);
}

void	init_textures(t_game *game)
{
	game->p.texture_n = mlx_load_png(game->config.north_texture);
	game->p.texture_s = mlx_load_png(game->config.south_texture);
	game->p.texture_w = mlx_load_png(game->config.west_texture);
	game->p.texture_e = mlx_load_png(game->config.east_texture);
}
