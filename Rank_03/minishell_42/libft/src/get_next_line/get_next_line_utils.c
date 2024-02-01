/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:02:11 by verdant           #+#    #+#             */
/*   Updated: 2022/12/25 12:34:07 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int	ft_strclen_bool(char *buf, bool search_newline)
{
	int	i;

	i = 0;
	if (search_newline)
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
				return (i);
			i++;
		}
		return (0);
	}
	while (buf[i])
		i++;
	return (i);
}

char	*ft_concat(char *s1, char *s2, int s1_len)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i + s1_len] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return (s1);
}

int	check_char(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
