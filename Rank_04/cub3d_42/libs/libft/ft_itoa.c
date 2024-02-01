/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 15:13:51 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/06/13 15:33:26 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

static int	positive_check(int num)
{
	if (num < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	long	num;
	int		min;
	int		len;
	char	*str;

	len = ft_intlen(n);
	num = n;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	min = positive_check(num);
	while (len > min)
	{
		len--;
		str[len] = ft_abs(num % 10) + '0';
		num /= 10;
	}
	if (min)
		str[len - 1] = '-';
	return (str);
}
