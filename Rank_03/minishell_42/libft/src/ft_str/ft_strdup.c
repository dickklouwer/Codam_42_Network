/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:17:53 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/21 13:22:17 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *source)
{
	int		size;
	char	*target;

	size = ft_strlen(source) + 1;
	target = (char *)malloc(size * sizeof(char));
	if (target == NULL)
		return (NULL);
	ft_strlcpy(target, (char *)source, size);
	return (target);
}
