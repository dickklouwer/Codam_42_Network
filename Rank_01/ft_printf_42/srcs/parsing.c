/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 13:36:43 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/04/05 09:52:01 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	parse_str(const char *str, t_lst *lst, va_list ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			convert_str((char *)str, lst, ap);
			if (*str == '%')
			{
				write (1, "%", 1);
				lst->pbytes++;
			}
		}
		else
		{
			write(1, str, 1);
			lst->pbytes++;
		}
		str++;
	}
	return (1);
}

static t_lst	reset_lst(t_lst *lst)
{
	lst->str = NULL;
	lst->num = 0;
	lst->i = 0;
	lst->u_hex = 0;
	lst->u_i = 0;
	return (*lst);
}

int	convert_str(char *str, t_lst *lst, va_list ap)
{
	if (*str == 's')
		print_str(lst, ap);
	if (*str == 'd' || *str == 'i')
	{
		lst->i = 1;
		convert_int(lst, ap);
	}
	if (*str == 'u')
		convert_int(lst, ap);
	if (*str == 'c')
		convert_char(lst, ap);
	if (*str == 'X' || *str == 'x')
	{
		if (*str == 'X')
			lst->u_hex = 1;
		convert_hex(lst, ap);
	}
	if (*str == 'p')
		convert_pointer(lst, ap);
	reset_lst(lst);
	return (1);
}

int	print_str(t_lst *lst, va_list ap)
{
	const char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		lst->pbytes += 6;
		return (1);
	}
	if (*str == (char) NULL)
		return (0);
	lst->pbytes += ft_strlen(str);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return (1);
}
