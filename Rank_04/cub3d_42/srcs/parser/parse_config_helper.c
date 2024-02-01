/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_config_helper.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 14:36:30 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/09/27 12:14:42 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_config_variables(t_game *game)
{
	if (game->config.north_texture != NULL)
		free(game->config.north_texture);
	if (game->config.south_texture != NULL)
		free(game->config.south_texture);
	if (game->config.west_texture != NULL)
		free(game->config.west_texture);
	if (game->config.east_texture != NULL)
		free(game->config.east_texture);
}

int	validate_config_variables(char *line, char **split_line)
{
	if (split_line[0][0] == '1' || split_line[0][0] == '0')
		return (EXIT_FAILURE);
	else if ((ft_strncmp("NO ", line, 3)) && (ft_strncmp("SO ", line, 3))
		&& (ft_strncmp("WE ", line, 3)) && (ft_strncmp("EA ", line, 3))
		&& (ft_strncmp("F ", line, 2)) && (ft_strncmp("C ", line, 2))
		&& !split_line[1])
		err_exit("Wrong variable in config file ...");
	return (EXIT_SUCCESS);
}

void	set_config_variables(t_config *config, char *line, char **lines)
{
	if (ft_strncmp("NO ", line, 3) == 0)
		config->north_texture = ft_strdup(lines[1]);
	else if (ft_strncmp("SO ", line, 3) == 0)
		config->south_texture = ft_strdup(lines[1]);
	else if (ft_strncmp("WE ", line, 3) == 0)
		config->west_texture = ft_strdup(lines[1]);
	else if (ft_strncmp("EA ", line, 3) == 0)
		config->east_texture = ft_strdup(lines[1]);
	else if (ft_strncmp("F ", line, 2) == 0)
		parse_color(config->floor_color, lines[1]);
	else if (ft_strncmp("C ", line, 2) == 0)
		parse_color(config->ceiling_color, lines[1]);
}

int	check_dup_config_vars(t_config *config, char *line)
{
	if (ft_strncmp("NO ", line, 3) == 0 && config->north_texture != NULL)
		return (EXIT_FAILURE);
	else if (ft_strncmp("SO ", line, 3) == 0 && config->south_texture != NULL)
		return (EXIT_FAILURE);
	else if (ft_strncmp("WE ", line, 3) == 0 && config->west_texture != NULL)
		return (EXIT_FAILURE);
	else if (ft_strncmp("EA ", line, 3) == 0 && config->east_texture != NULL)
		return (EXIT_FAILURE);
	else if (ft_strncmp("F ", line, 2) == 0 && config->floor_color[0] != -1)
		return (EXIT_FAILURE);
	else if (ft_strncmp("C ", line, 2) == 0 && config->ceiling_color[0] != -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
