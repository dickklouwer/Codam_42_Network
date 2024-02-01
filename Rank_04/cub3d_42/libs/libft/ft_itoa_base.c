/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 09:52:54 by dickklouwer   #+#    #+#                 */
/*   Updated: 2022/03/23 12:30:45 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_base(size_t n, int base)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(size_t n, char *set, int base)
{
	char	*p;
	int		len;
	size_t	num;

	if (n == 0)
		return (p = "0");
	len = ft_intlen_base(n, base);
	num = n;
	p = ft_calloc(len + 1, sizeof(char));
	while (len)
	{
		len--;
		p[len] = set[num % base];
		num /= base;
	}
	return (p);
}
