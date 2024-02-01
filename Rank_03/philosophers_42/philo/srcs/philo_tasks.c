/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_tasks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:09:26 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/01/20 14:08:53 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	done_eating(t_data *data, t_philo *philo)
{
	long long	i;

	i = 0;
	if (philo->must_eat < 0)
		return (-1);
	if (philo->must_eat == 0)
	{
		while (i < data->num_philos)
		{
			if (data->philo[i].must_eat > 0)
				return (0);
			i++;
		}
		data->finished = 1;
	}
	return (1);
}

int	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_mutex);
	if (philo->data->finished)
	{
		pthread_mutex_unlock(philo->data->write_mutex);
		return (EXIT_FAILURE);
	}
	print_log(philo, FORK);
	pthread_mutex_unlock(philo->data->write_mutex);
	return (EXIT_SUCCESS);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	philo->done = pick_fork(philo);
	if (philo->lfork == philo->rfork)
	{
		pthread_mutex_unlock(philo->rfork);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(philo->rfork);
	if (pick_fork(philo))
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(philo->data->write_mutex);
	print_log(philo, EATING);
	philo->time_last_eat = get_current_time();
	pthread_mutex_unlock(philo->data->write_mutex);
	philo->must_eat--;
	done_eating(philo->data, philo);
	p_sleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (EXIT_SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_mutex);
	if (philo->data->finished)
	{
		pthread_mutex_unlock(philo->data->write_mutex);
		return (EXIT_FAILURE);
	}
	print_log(philo, SLEEPING);
	pthread_mutex_unlock(philo->data->write_mutex);
	p_sleep(philo->data, philo->data->time_to_sleep);
	return (EXIT_SUCCESS);
}

int	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_mutex);
	if (philo->data->finished)
	{
		pthread_mutex_unlock(philo->data->write_mutex);
		return (EXIT_FAILURE);
	}
	print_log(philo, THINKING);
	pthread_mutex_unlock(philo->data->write_mutex);
	return (EXIT_SUCCESS);
}
