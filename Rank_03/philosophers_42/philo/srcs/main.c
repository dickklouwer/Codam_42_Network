/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 13:27:07 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/01/20 14:13:00 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	destroy_chopsticks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_destroy(&data->chopsticks[i]))
			return (printf("Failed to destroy mutex"), 1);
		i++;
	}
	free(data->chopsticks);
	if (pthread_mutex_destroy(data->write_mutex))
		return (printf("Failed to destroy mutex"), 1);
	free(data->write_mutex);
	return (EXIT_SUCCESS);
}

static int	join_threads(t_data *data)
{
	long long	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(*data->philo[i].philo_t, NULL))
			return (EXIT_FAILURE);
		free(data->philo[i].philo_t);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_input(&data, argv, argc))
		return (EXIT_FAILURE);
	if (philo_threads(&data))
	{
		destroy_chopsticks(&data);
		return (EXIT_FAILURE);
	}
	join_threads(&data);
	destroy_chopsticks(&data);
	return (EXIT_SUCCESS);
}
