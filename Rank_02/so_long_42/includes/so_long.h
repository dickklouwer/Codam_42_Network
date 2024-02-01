/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 14:36:48 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/01 13:49:29 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXELS     64
# define HEIGHT     1080
# define WIDTH      1920

# include	<stdlib.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<fcntl.h>

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line.h"
# include "../libs/ft_printf/includes/libftprintf.h"

typedef struct s_map
{
	char	**map;
	int		cntrl;
	int		end;
	int		coll;
	int		exit;
	int		start;
	int		height;
	int		width;
	int		inv_exit;
	int		inv_start;
}				t_map;

typedef struct s_path
{
	char	*wall;
	char	*grass;
	char	*collectible;
	char	*player;
	char	*exit;
}				t_path;

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_game
{
	t_map				*map;
	mlx_t				*mlx;
	xpm_t				*xpm;
	mlx_image_t			*img;
	mlx_key_data_t		*key_data;
	t_player			player;
	t_path				*path;
	int					movements;
}				t_game;

// PARSE MAP
int		parse_map(t_game *data, char *file);

// UTILS
int		error(char *msg);
void	free_arr(char **arr, int i);
int		array_copy(char **dst, char **src, int n);

// BUILD MAP
void	my_keyhook(mlx_key_data_t key_data, void *param);
int		build_map(t_game *game);

// FLOOD FILL
int		flood_fill(int x, int y, t_game *game, char **map);

// GAME CONTROL
void	update_map(t_game *game, int x, int y, char tile);
void	update_player(t_game *game, int x, int y);
int		game_control(t_game *game, char tile);
int		exit_game(t_game *game, int in_game);

#endif