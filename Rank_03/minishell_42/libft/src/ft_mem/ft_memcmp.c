/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:45:49 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/11 13:57:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n && (s1[i] == s2[i]))
		i++;
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

// int main()
// {
// 	char s1[] = "";
// 	char s2[] = "";
// 	printf("%d\t", memcmp(s1, s2, 20 * sizeof(s1[0])));
// 	printf("%d\t", ft_memcmp(s1, s2, 20 * sizeof(s1[0])));
// }