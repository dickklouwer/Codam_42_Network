/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 15:13:51 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/04/05 09:54:03 by tklouwer      ########   odam.nl         */
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

static int	ft_intlen(int n)
{
	int	len;

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
