/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 11:24:15 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/04/04 15:37:45 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static t_lst	init_list(t_lst *lst)
{
	lst->str = NULL;
	lst->num = 0;
	lst->i = 0;
	lst->u_hex = 0;
	lst->pbytes = 0;
	lst->u_i = 0;
	return (*lst);
}

int	ft_printf(const char *str, ...)
{
	t_lst	lst;
	va_list	ap;

	if (!str)
		return (-1);
	init_list(&lst);
	va_start(ap, str);
	parse_str(str, &lst, ap);
	va_end(ap);
	return (lst.pbytes);
}
