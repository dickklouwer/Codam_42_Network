/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 11:45:49 by bprovoos      #+#    #+#                 */
/*   Updated: 2023/09/26 14:56:22 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	st_file_check(char *file)
{
	char	*filename;

	filename = ft_strnstr(file, ".", ft_strlen(file) + 1);
	if (!filename || ft_strncmp(filename, ".cub", 4)
		|| ft_strlen(filename) != 4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	err_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	input_check(int argc, char **argv)
{
	if (argc != 2)
		err_exit("cub3D: 2 Arguments required\n");
	if (st_file_check(argv[1]))
		err_exit("Wrong config file extension");
}
