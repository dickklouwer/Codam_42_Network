/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 11:15:37 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/08/21 19:51:36 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	input_check(argc, argv);
	map_init(&game.map, argv);
	config_init(&game.config, argv);
	parse_map_file(&game);
	init_screen(&game.mlx);
	init_player(&game);
	init_textures(&game);
	draw_screen(&game);
	mlx_loop_hook(game.mlx, key_pressed, &game);
	mlx_loop(game.mlx);
	delete_textures(&game);
	free_config_variables(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
