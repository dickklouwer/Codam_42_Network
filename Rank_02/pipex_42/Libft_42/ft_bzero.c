/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/23 12:10:00 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/10/26 12:07:48 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *temp;

	temp = s;
	while (n > 0)
	{
		n--;
		*temp = 0;
		temp++;
	}
}
