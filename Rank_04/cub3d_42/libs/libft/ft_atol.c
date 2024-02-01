/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 13:49:28 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/09/27 09:48:27 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atol(const char *str)
{
	long	res;
	int		min;
	int		i;

	i = 0;
	res = 0;
	min = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (min * res);
}
