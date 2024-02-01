/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 14:59:21 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/11/30 09:13:43 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
** The move functions lets the player move in one of the 4 directions on the
**	X- and Y- axis.
*/
void	move_up(t_game *game, int x, int y)
{
	if (game_control(game, game->map->map[y - 1][x]))
		return ;
	update_map(game, x, y, '0');
	update_map(game, x, y - 1, 'P');
	update_player(game, x, y - 1);
}

void	move_down(t_game *game, int x, int y)
{
	if (game_control(game, game->map->map[y + 1][x]))
		return ;
	update_map(game, x, y, '0');
	update_map(game, x, y + 1, 'P');
	update_player(game, x, y + 1);
}

void	move_left(t_game *game, int x, int y)
{
	if (game_control(game, game->map->map[y][x - 1]))
		return ;
	update_map(game, x, y, '0');
	update_map(game, x - 1, y, 'P');
	update_player(game, x - 1, y);
}

void	move_right(t_game *game, int x, int y)
{
	if (game_control(game, game->map->map[y][x + 1]))
		return ;
	update_map(game, x, y, '0');
	update_map(game, x + 1, y, 'P');
	update_player(game, x + 1, y);
}

/* 
** Registers the keyboard action and executes based on the pressed key. 
*/
void	my_keyhook(mlx_key_data_t key_data, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		move_up(game, game->player.x, game->player.y);
	if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
		move_down(game, game->player.x, game->player.y);
	if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
		move_right(game, game->player.x, game->player.y);
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
		move_left(game, game->player.x, game->player.y);
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		exit_game(game, 0);
	build_map(game);
}
