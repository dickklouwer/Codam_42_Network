/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 11:37:05 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/04/05 09:53:25 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h> 
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_lst
{
	char			*str;
	int				num;
	unsigned int	u_i;
	int				i;
	int				u_hex;
	size_t			pbytes;
}				t_lst;

int		ft_printf(const char *str, ...);
int		parse_str(const char *str, t_lst *lst, va_list ap);
int		convert_str(char *str, t_lst *lst, va_list ap);
int		print_str(t_lst *lst, va_list ap);
int		convert_int(t_lst *lst, va_list ap);
int		convert_char(t_lst *lst, va_list ap);
int		convert_hex(t_lst *lst, va_list ap);
int		convert_pointer(t_lst *lst, va_list ap);
#endif