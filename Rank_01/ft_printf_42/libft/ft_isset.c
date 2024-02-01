/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 11:27:31 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/03/21 11:27:48 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(int c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
