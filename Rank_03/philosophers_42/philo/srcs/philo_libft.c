/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_libft.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 14:59:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/01/19 15:41:58 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <limits.h>

int	only_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			min;
	int			i;

	i = 0;
	res = 0;
	min = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > INT_MAX || min == -1)
		return (-1);
	else
		return (min * res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*u_ptr;
	int				n;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	n = count * size;
	u_ptr = (unsigned char *)ptr;
	while (n > 0)
	{
		n--;
		*u_ptr = 0;
		u_ptr++;
	}
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
