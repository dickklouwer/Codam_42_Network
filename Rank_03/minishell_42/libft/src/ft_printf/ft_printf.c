/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:50:42 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/22 13:17:01 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	format_conversion(char c, va_list args)
{
	size_t	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		print_len += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		print_len += ft_putptr(va_arg(args, unsigned long));
	else if (c == 'u')
		print_len += ft_putuint(va_arg(args, unsigned int));
	else if (c == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	size_t	print_len;
	va_list	args;

	i = 0;
	print_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			print_len += format_conversion(format[i++], args);
		}
		else if (format[i] != '%')
		{
			len = ft_strclen(&format[i], '%');
			print_len += write(1, &format[i], len);
			i += len;
		}
		else
			i++;
	}
	return (va_end(args), print_len);
}
