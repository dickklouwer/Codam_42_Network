/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 13:47:29 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/08/21 19:33:58 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_isdigit_cub3d(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (EXIT_SUCCESS);
}

size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	count;

	count = 0;
	while (*str && ft_strchr(accept, *str))
	{
		count++;
		str++;
	}
	return (count);
}

void	parse_color(int *color, char *line)
{
	char	**color_code;
	int		i;

	i = 0;
	color_code = ft_split(line, ',');
	while (color_code[i])
	{
		if (ft_isdigit_cub3d(color_code[i]))
			err_exit("Invalid color code");
		color[i] = ft_atoi(color_code[i]);
		if (color[i] > 255 || color[i] < 0)
			err_exit("Invalid color code");
		free(color_code[i]);
		i++;
	}
	free(color_code);
}
