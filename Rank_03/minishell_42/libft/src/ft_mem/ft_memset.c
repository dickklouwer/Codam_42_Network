/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:41:39 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/11 13:57:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char *)b)[index] = (unsigned char )c;
		index++;
	}
	return (b);
}

// int main()
// {
// 	char a[20] = "Programm";
// 	printf("%s\n", a);
// 	printf("%s\n", ft_memset(a, '$', 3));
// 	// printf("%s", memset(a, '$', 3));
// }