/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:43:55 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/11 21:52:36 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char )c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	const char str[] = "Find the a";
// 	int c = 'n';
// 	size_t n = 2;
// 	printf("%s\t", ft_memchr(str, c , n));
// 	printf("%s", memchr(str, c, n));
// }