/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:33:17 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 17:54:49 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static int	check(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	if (philo->min_eat > 0 && philo->finish == 0)
	{
		if (philo->meals >= philo->min_eat)
		{
			philo->input->num_overate++;
			philo->finish = 1;
		}
	}
	pthread_mutex_unlock(philo->mutex);
	pthread_mutex_lock(philo->mutex);
	if (philo->input->num_overate == philo->input->number)
	{
		pthread_mutex_unlock(philo->mutex);
		return (0);
	}
	pthread_mutex_unlock(philo->mutex);
	return (1);
}

static int	philo_eat(t_philo *philo)
{
	if (!check(philo))
		return (1);
	pthread_mutex_lock(philo->min_fork);
	ft_print_action(GET_FORK, 0, philo);
	pthread_mutex_lock(philo->max_fork);
	ft_print_action(GET_FORK, 0, philo);
	pthread_mutex_lock(philo->mutex);
	philo->last_ate = get_time();
	philo->meals++;
	ft_print_action(EATING, 0, philo);
	pthread_mutex_unlock(philo->mutex);
	ft_sleep(philo->input->t_eat);
	pthread_mutex_unlock(philo->max_fork);
	pthread_mutex_unlock(philo->min_fork);
	return (0);
}

static void	min_max_fork(t_philo *philo)
{
	philo->min_fork = philo->left_fork;
	philo->max_fork = philo->right_fork;
	if (philo->num_right < philo->num_left)
	{
		philo->min_fork = philo->right_fork;
		philo->max_fork = philo->left_fork;
	}
}

void	*ft_start(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	min_max_fork(philo);
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (philo_eat(philo))
			return (NULL);
		if (!check(philo))
			return (NULL);
		ft_print_action(PH_SLEEP, 0, philo);
		ft_sleep(philo->input->t_sleep);
		if (!check(philo))
			return (NULL);
		ft_print_action(PH_THINK, 0, philo);
		if (!check(philo))
			return (NULL);
	}
	return (NULL);
}
