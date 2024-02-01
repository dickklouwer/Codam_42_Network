/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:50:59 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/22 12:17:46 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_putstr(char *s)
{
	size_t	word_len;

	word_len = 0;
	if (!s)
		return (word_len += write(1, "(null)", 6));
	word_len = ft_strlen(s);
	write(1, s, word_len);
	return (word_len);
}

size_t	ft_putnbr(int nb)
{
	size_t	number_len;
	size_t	base_nb;
	long	num;

	number_len = 0;
	base_nb = 10;
	num = nb;
	if (num < 0)
	{
		num *= -1;
		number_len += write(1, "-", 1);
	}
	number_len += ft_base_toa(num, base_nb, "0123456789");
	return (number_len);
}

size_t	ft_puthex(unsigned int nb, char c)
{
	size_t	number_len;

	number_len = 0;
	if (c == 'x')
		number_len += ft_base_toa(nb, 16, "0123456789abcdef");
	else
		number_len += ft_base_toa(nb, 16, "0123456789ABCDEF");
	return (number_len);
}

size_t	ft_putptr(unsigned long nb)
{
	size_t	number_len;

	number_len = 0;
	number_len += write(1, "0x", 2);
	if ((void *)nb == NULL)
	{
		number_len += write(1, "0", 1);
		return (number_len);
	}
	number_len += ft_base_toa(nb, 16, "0123456789abcdef");
	return (number_len);
}

size_t	ft_putuint(unsigned int nb)
{
	size_t	number_len;

	number_len = ft_base_toa(nb, 10, "0123456789");
	return (number_len);
}
