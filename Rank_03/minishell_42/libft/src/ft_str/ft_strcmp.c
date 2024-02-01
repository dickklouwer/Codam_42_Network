/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: verdant <verdant@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:11:27 by verdant       #+#    #+#                 */
/*   Updated: 2023/04/25 15:28:40 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	index;

	index = 0;
	while (str1[index] || str2[index])
	{
		if ((unsigned char)str1[index] > (unsigned char)str2[index])
			return (1);
		if ((unsigned char)str2[index] > (unsigned char)str1[index])
			return (-1);
		index++;
	}
	return (0);
}
