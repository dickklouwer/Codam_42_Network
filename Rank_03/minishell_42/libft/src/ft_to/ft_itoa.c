/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:03:12 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/23 18:15:58 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long int value)
{
	int	counter;

	counter = 0;
	if (value < 1)
	{
		counter++;
		value *= -1;
	}
	while (value > 0)
	{
		value = value / 10;
		counter++;
	}
	return (counter);
}

static char	*fill_arr(long int value, int counter, char *int_str)
{
	int_str[counter] = 0;
	if (counter == 1)
	{
		int_str[0] = value % 10 + '0';
		return (int_str);
	}
	while (counter--)
	{
		int_str[counter] = value % 10 + '0';
		value = value / 10;
	}
	if (int_str[0] == '0')
		int_str[0] = '-';
	return (int_str);
}

char	*ft_itoa(int n)
{
	int			counter;
	char		*int_str;
	long int	value;

	value = n;
	counter = count_len(value);
	int_str = malloc((counter + 1) * sizeof(char));
	if (!int_str)
		return (0);
	if (n < 0)
		value *= -1;
	return (fill_arr(value, counter, int_str));
}
