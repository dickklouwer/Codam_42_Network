/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_time.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 14:54:24 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/01/20 11:42:09 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static u_int64_t	sec_to_millisec(u_int64_t sec)
{
	u_int64_t	millisec;

	millisec = sec * 1000;
	return (millisec);
}

static u_int64_t	microsec_to_millisec(u_int64_t microsec)
{
	u_int64_t	millisec;

	millisec = microsec / 1000;
	return (millisec);
}

u_int64_t	get_current_time(void)
{
	struct timeval	tv;
	u_int64_t		cur_time_ms;

	gettimeofday(&tv, NULL);
	cur_time_ms = (u_int64_t)sec_to_millisec(tv.tv_sec) + \
	microsec_to_millisec(tv.tv_usec);
	return (cur_time_ms);
}

/*  MORE ACCURATE VERSION OF USLEEP
 */
void	p_sleep(t_data *data, long long ms)
{
	struct timeval	start;
	struct timeval	end;	

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&end, NULL);
		if ((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec)
			/ 1000 >= ms)
			return ;
		if (data->num_philos < 10)
			usleep(100);
		else
			usleep(1000);
	}
}
