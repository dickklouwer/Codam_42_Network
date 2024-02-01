/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 11:53:48 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/01 12:01:52 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* 
** deallocates the assigned memory.
*/
void	free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return ;
}

/* 
**	puts error message and exit's the program.
*/
int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
	return (EXIT_FAILURE);
}
