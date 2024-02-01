/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:28:21 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/25 13:40:46 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	count_len(unsigned long value, int base_nb)
{
	int	counter;

	counter = 0;
	if (value == 0)
		counter++;
	while (value > 0)
	{
		value = value / base_nb;
		counter++;
	}
	return (counter);
}

static void	fill_arr(unsigned long nb, char *str, int base_nb, char *base_str)
{
	int	counter;

	counter = count_len(nb, base_nb);
	str[counter] = '\0';
	if (counter == 1)
	{
		str[0] = base_str[nb % base_nb];
		return ;
	}
	while (counter)
	{
		counter--;
		str[counter] = base_str[nb % base_nb];
		nb /= base_nb;
	}
}

size_t	ft_base_toa(unsigned long nb, int base_nb, char *base_str)
{
	int			counter;
	char		*str;

	counter = count_len(nb, base_nb);
	str = malloc((counter + 1) * sizeof(char));
	if (!str)
		return (0);
	fill_arr(nb, str, base_nb, base_str);
	write(1, str, counter);
	free(str);
	return (counter);
}
