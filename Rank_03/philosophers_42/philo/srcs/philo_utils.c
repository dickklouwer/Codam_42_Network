/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:17:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/01/20 14:06:06 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_log(t_philo *philo, int state)
{
	uint64_t	time;

	time = (get_current_time() - philo->data->start_time);
	if (state == EATING)
		printf("%llu %d is eating\n", time, philo->id);
	else if (state == FORK)
		printf("%llu %d picked up a fork\n", time, philo->id);
	else if (state == SLEEPING)
		printf("%llu %d is sleeping\n", time, philo->id);
	else if (state == THINKING)
		printf("%llu %d is thinking\n", time, philo->id);
	else if (state == DIED && philo->data->finished == 0)
	{
		philo->data->finished = 1;
		printf("%llu %d died\n", time, philo->id);
		return (1);
	}
	return (0);
}
