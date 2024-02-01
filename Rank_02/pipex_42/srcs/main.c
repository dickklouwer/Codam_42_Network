/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 12:29:37 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/20 14:31:09 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		error("NOT CORRECT AMOUNT ARGS", 2);
	if (parse_path(&data, argv, envp))
		exit (EXIT_FAILURE);
	exit(pipex(&data, envp));
}
