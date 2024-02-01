/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:59:27 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/01/30 08:34:49 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_checks(t_data *data)
{
	if (data->num_philos > 200)
		return (printf("./philo no more then 200 philos allowed\n"), 1);
	if (data->time_to_die < 0 || data->time_to_sleep < 0
		|| data->time_to_eat < 0)
		return (printf("./philo time_to_* only 60ms > allowed.\n"), 1);
	if (data->num_philos < 0 || data->num_philos == 0)
		return (printf("./philo atleast one philo needed.\n"), 1);
	return (EXIT_SUCCESS);
}

static int	chopsticks_init(t_data *data)
{
	int	i;

	i = 0;
	data->chopsticks = ft_calloc(data->num_philos, sizeof(pthread_mutex_t));
	if (!data->chopsticks)
		return (printf("Memory allocation failed"), 1);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->chopsticks[i], NULL))
			return (printf("Mutex initialization failed"), 1);
		i++;
	}
	data->write_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(data->write_mutex, NULL))
		return (printf("Mutex initialization failed"), 1);
	return (EXIT_SUCCESS);
}

static int	philosophers_init(t_data *data)
{
	int	i;

	i = 0;
	data->philo = ft_calloc(data->num_philos + 1, sizeof(t_philo));
	if (!data->philo)
		return (printf("Memory allocation failed"), 1);
	while (i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].done = 0;
		data->philo[i].data = data;
		data->philo[i].must_eat = data->n_must_eat;
		data->philo[i].lfork = &data->chopsticks[i];
		data->philo[i].rfork = &data->chopsticks[((i + 1) % data->num_philos)];
		data->philo[i].philo_t = ft_calloc(1, sizeof(pthread_t));
		if (!data->philo[i].philo_t)
			return (EXIT_FAILURE);
		i++;
	}
	if (i == data->num_philos)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	data_init(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->n_must_eat = ft_atoi(argv[5]);
		if (data->n_must_eat < 0)
			return (EXIT_FAILURE);
	}
	if (!argv[5])
		data->n_must_eat = -1;
	if (chopsticks_init(data))
		return (EXIT_FAILURE);
	if (init_checks(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_input(t_data *data, char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (printf("./philo: missing arguments"), 1);
	while (i < argc)
	{
		if (only_num(argv[i]))
			return (printf("./philo: only non-negative input allowed\n"), 1);
		i++;
	}
	if (data_init(data, argv))
		return (1);
	if (philosophers_init(data))
		return (printf("./philo: Philosophers initialization failed"), 1);
	return (EXIT_SUCCESS);
}
