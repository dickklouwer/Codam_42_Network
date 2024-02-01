/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:00:16 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/16 17:22:35 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*search_s1;
	char	*set_string;
	int		i;

	search_s1 = (char *)s1;
	set_string = (char *)set;
	i = 0;
	while (ft_strchr(set_string, *search_s1) && search_s1[i])
		search_s1++;
	i = ft_strlen(search_s1);
	while (ft_strchr(set_string, search_s1[i]) && i != 0)
		i--;
	return (ft_substr(search_s1, 0, i + 1));
}
