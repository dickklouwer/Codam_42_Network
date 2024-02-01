/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:16:15 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/21 14:10:17 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (0);
}

// int main(void)
// {
// 	char s[] = "Hello Hello";
// 	char c = '\0';
// 	// printf("%s", strrchr(s, c));
// 	printf("|%s|\n", ft_strrchr(s, c));
// }
