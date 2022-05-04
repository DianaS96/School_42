/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:42:43 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 18:52:47 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

/*
If a philosopher didn’t start eating time_to_die milliseconds 
since the beginning of their last meal or the beginning of the simulation, 
they die.
*/
int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	if (get_time() - philo->last_ate > philo->input->t_die)
	{
		pthread_mutex_unlock(philo->mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex);
	return (0);
}

int	ft_forks_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.number)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	return (0);
}

/*
pthread_join is called from another thread (usually the thread that created it) 
to wait for a thread to terminate and obtain its return value.
*/
int	ft_check_meals(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->mutex);
	if (philo->meals >= philo->min_eat && \
	data->input.num_overate == data->input.number)
	{
		pthread_mutex_unlock(philo->mutex);
		ft_join_threads(data);
		return (0);
	}
	pthread_mutex_unlock(philo->mutex);
	return (1);
}

int	ft_detach_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		pthread_detach(data->philo[i].thread);
		i++;
	}
	return (0);
}

/*
https://stackoverflow.com/questions/22427007/
difference-between-pthread-exit-pthread-join-and-pthread-detach
*/
/*
pthread_detach can be called from either the thread itself or another thread, 
and indicates that you don't want the thread's return value or 
the ability to wait for it to finish. 
*/
/*
https://man7.org/linux/man-pages/man3/pthread_create.3.html
Making a thread detached is useful for some types of daemon threads 
whose exit status the application does not need to care about.
*/

int	ft_check_dead(t_data *data)
{
	int		i;

	i = 0;
	while (i <= data->input.number)
	{
		if (i == data->input.number)
			i = 0;
		if (ft_is_dead(&data->philo[i]))
		{
			ft_detach_threads(data);
			ft_print_action(FPURPLE PHILO_DEAD NONE, 0, &data->philo[i]);
			pthread_mutex_lock(data->philo[i].msg);
			ft_forks_destroy(data);
			return (1);
		}
		if (data->input.min_eat > 0 && !ft_check_meals(&data->philo[i], data))
		{
			pthread_mutex_lock(&data->msg);
			printf(FGREEN"All philos ate at least %i time\n"NONE, \
			data->input.min_eat);
			return (1);
		}
		i++;
	}
	return (0);
}
