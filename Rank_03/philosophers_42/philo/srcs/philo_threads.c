/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 15:05:22 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/01/20 14:05:54 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	died(t_data *data)
{
	uint64_t	curr_time;
	long long	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(data->write_mutex);
		curr_time = get_current_time();
		if ((curr_time - data->philo[i % data->num_philos].time_last_eat)
			> (uint64_t) data->time_to_die)
		{
			print_log(&data->philo[i % data->num_philos], DIED);
			pthread_mutex_unlock(data->write_mutex);
			break ;
		}
		i++;
		pthread_mutex_unlock(data->write_mutex);
	}
}

void	*philo(void *philosopher)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philosopher;
	data = philo->data;
	if (philo->id % 2 == 0)
		p_sleep(philo->data, 10);
	while (1)
	{
		if (eating(philo))
			return (EXIT_SUCCESS);
		philo_sleep(philo);
		thinking(philo);
	}
	return (EXIT_SUCCESS);
}

int	philo_threads(t_data *data)
{
	long long	i;

	i = 0;
	data->finished = 0;
	data->start_time = get_current_time();
	while (i < data->num_philos)
	{
		data->philo[i].time_last_eat = data->start_time;
		if (pthread_create(data->philo[i].philo_t,
				NULL, &philo, &data->philo[i]))
		{
			data->finished = 1;
			return (EXIT_FAILURE);
		}
		i++;
	}
	died(data);
	return (EXIT_SUCCESS);
}
