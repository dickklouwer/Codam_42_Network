/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:04:28 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/04/05 09:54:20 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	convert_int(t_lst *lst, va_list ap)
{
	unsigned int	nmbr;

	nmbr = 0;
	if (lst->i == 1)
	{
		lst->num = va_arg(ap, int);
		lst->str = ft_itoa(lst->num);
	}
	else
	{
		nmbr = va_arg(ap, unsigned int);
		if (nmbr == 0)
		{
			write(1, "0", 1);
			return (lst->pbytes += 1);
		}
		else
			lst->str = ft_itoa_base(nmbr, "0123456789", 10);
	}
	lst->pbytes += ft_strlen(lst->str);
	ft_putstr_fd(lst->str, 1);
	free(lst->str);
	return (1);
}

int	convert_hex(t_lst *lst, va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (lst->pbytes += 1);
	}
	if (num >= 0)
	{
		if (lst->u_hex)
			lst->str = ft_itoa_base(num, "0123456789ABCDEF", 16);
		else
			lst->str = ft_itoa_base(num, "0123456789abcdef", 16);
		lst->pbytes += (ft_strlen(lst->str));
		ft_putstr_fd(lst->str, 1);
		if (lst->str)
			free(lst->str);
		return (1);
	}
	else
		return (0);
}

int	convert_pointer(t_lst *lst, va_list ap)
{
	size_t	ptr;

	ptr = (size_t)va_arg(ap, void *);
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		lst->pbytes += 3;
	}
	else
	{
		lst->str = ft_itoa_base(ptr, "0123456789abcdef", 16);
		write(1, "0x", 2);
		lst->pbytes += (ft_strlen(lst->str) + 2);
		ft_putstr_fd(lst->str, 1);
		free(lst->str);
	}
	return (1);
}

int	convert_char(t_lst *lst, va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	lst->pbytes += 1;
	return (0);
}
