/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 14:36:12 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/01 13:41:07 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
** Static funtions will be declared as "ST_function_name".
*/
t_game	*st_game_init(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->path = ft_calloc(1, sizeof(t_path));
	if (!game->map || !game->path)
		error("MEMORY ALLOCATION ERROR\n");
	return (game);
}

/* 
**	STRNSTR takes the extension and compares the values to a ".ber" file.
*/
int	st_file_check(char *file)
{
	const char	*filename;

	filename = ft_strnstr(file, ".", ft_strlen(file) + 1);
	if (!filename || ft_strncmp(filename, ".ber", ft_strlen(filename)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* 
**	Executes and makes sure that the game runs smooth with the given input. 	
*/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || st_file_check(argv[1]))
		error("INVALID '.BER' FILE.\n");
	st_game_init(&game);
	if (parse_map(&game, argv[1]))
		return (EXIT_FAILURE);
	game.mlx = mlx_init(game.map->width * PIXELS,
			game.map->height * PIXELS, "POKEMON FIRE RED", 0);
	build_map(&game);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}
