/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 08:44:02 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 11:02:35 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_double(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	check_only_int(char *argv)
{
	if (*argv == '-')
		argv++;
	if (!*argv)
		return (EXIT_FAILURE);
	while (*argv)
	{
		if (!ft_isdigit(*argv))
			return (EXIT_FAILURE);
		argv++;
	}
	return (EXIT_SUCCESS);
}

static int	valid_input(char **argv, int argc)
{
	long	nb_argv;
	int		i;

	i = 1;
	nb_argv = 0;
	if (!*argv)
		return (EXIT_FAILURE);
	if (check_double(argv, argc))
		return (EXIT_FAILURE);
	while (argv[i])
	{
		nb_argv = ft_atol(argv[i]);
		if (check_only_int(argv[i]))
			return (EXIT_FAILURE);
		if ((nb_argv > INT_MAX) || (nb_argv < INT_MIN))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	fill_stack(t_stack **s, char **argv, int argc)
{
	t_stack	*temp;
	int		i;
	int		nb;

	i = 1;
	nb = 0;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		temp = ft_stcknew(nb);
		if (!temp)
		{
			free(temp);
			break ;
		}
		temp->index = -1;
		ft_stckadd_back(s, temp);
		i++;
	}
}

int	parse_stack(t_stack **s, char **argv, int argc)
{
	if (valid_input(argv, argc))
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	fill_stack(s, argv, argc);
	return (EXIT_SUCCESS);
}
