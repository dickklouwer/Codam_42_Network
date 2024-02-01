/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 11:47:25 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 12:01:20 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_prerequisites(t_game *game, char *line, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1')
		{
			if (line[i] == 'W' || line[i] == 'E'
				|| line[i] == 'S' || line[i] == 'N')
			{
				game->p.start_x = i + 1;
				game->p.start_y = y + 1;
				game->p.orientation = line[i];
				game->p.player_count++;
			}
			else if (line[i] == ' ')
				i++;
			else
				err_exit("Map exist of invalid characters ...");
		}
		i++;
	}
}
