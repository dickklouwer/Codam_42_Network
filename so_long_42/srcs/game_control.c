/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_control.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 07:37:44 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/11/30 14:48:54 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
** Updates the player position on the map.
*/
void	update_player(t_game *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
}

/* 
** Updates the tile on the X- and Y- axis on the map.
*/
void	update_map(t_game *game, int x, int y, char tile)
{
	game->map->map[y][x] = tile;
}

/* 
** If the player found the exit in the map, the game ends. 
** the in_game_exit makes sure this process gets executed smoothly
** and displays the end score.
*/
static void	st_in_game_exit(t_game *game, int cntrl, int coll)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	game->movements++;
	update_map(game, x, y, '0');
	update_map(game, x, y, 'W');
	update_player(game, x, y);
	ft_printf("TOTAL MOVEMENTS: %d\n", game->movements);
	if (cntrl == coll)
		ft_printf("YOU'VE WON, YOU CATCHED %d POKE BALL(S)!\n", coll);
	else
	{
		ft_printf("YOU'VE PICKED UP %d POKÉ BALL(S)! \n", cntrl);
		ft_printf("YOU'RE MISSING %d POKÉ BALL(S).\n", coll - cntrl);
		ft_printf("GAME CLOSED");
	}
	return ;
}

/* 
**	Exit the game properly.
*/
int	exit_game(t_game *game, int in_game)
{
	if (in_game)
	{
		st_in_game_exit(game, game->map->cntrl, game->map->coll);
		mlx_delete_image(game->mlx, game->img);
		mlx_terminate(game->mlx);
		exit(1);
	}
	else
	{
		mlx_delete_image(game->mlx, game->img);
		mlx_terminate(game->mlx);
		ft_putstr_fd("GAME CLOSED", 1);
		exit (1);
	}
}

/* 
** Checks if the executed move is possible and displays a message if necessary.
*/
int	game_control(t_game *game, char tile)
{
	if (tile == '1')
		return (1);
	if (tile == 'E')
	{
		if (game->map->coll == game->map->cntrl)
			exit_game(game, 1);
		ft_printf("RETURN WHEN YOU'VE CATCHED THEM ALL!\n");
		ft_printf("MISSING %d OF %d POKÉ BALLS!\n",
			game->map->cntrl, game->map->coll);
		return (1);
	}
	if (tile == 'C')
	{
		game->movements++;
		ft_printf("MOVEMENTS: %d\n", game->movements);
		game->map->cntrl++;
		ft_printf("YOU'VE PICKED UP A POKÉ BALL, GOTTA CATCH 'M ALL!\n");
	}
	if (tile == '0')
	{
		game->movements++;
		ft_printf("MOVEMENTS: %d\n", game->movements);
		return (0);
	}
	return (0);
}
