/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 15:13:51 by tklouwer      #+#    #+#                 */
/*   Updated: 2020/11/13 16:24:00 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int i)
{
	return (i < 0) ? -i : i;
}

static int	ft_intlen(int n)
{
	int len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

char		*ft_itoa(int n)
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
	min = (num < 0) ? 1 : 0;
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
