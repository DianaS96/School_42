/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:24:10 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 17:51:59 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

/*
Create mutex for n forks (n = num of philos).
For each philo specify left and right fork.
Left fork for i-th philo has number i in array of forks.
Right fork for i-th philo has number (i + 1) in array of forks.
Right fork for the last philo is left fork for the first one.
*/
int	ft_init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->input.number);
	if (!data->forks)
		return (ft_error(2));
	while (i < data->input.number)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (ft_error(6));
		i++;
	}
	i = 0;
	while (i < data->input.number)
	{
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->input.number];
		data->philo[i].num_left = i;
		data->philo[i].num_right = (i + 1) % data->input.number;
		i++;
	}
	return (0);
}

/*
Allocate memory for array of philos;
Fill array of philos with necessary data;
*/
int	ft_init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->input.number);
	if (!data->philo)
		return (ft_error(2));
	data->input.num_overate = 0;
	data->num = data->input.number;
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->meals_mutex, NULL);
	while (i < data->input.number)
	{
		data->philo[i].finish = 0;
		data->philo[i].min_eat = data->input.min_eat;
		data->philo[i].id = i + 1;
		data->philo[i].last_ate = 0;
		data->philo[i].input = &data->input;
		data->philo[i].meals = 0;
		data->philo[i].last_ate = data->input.start_time;
		data->philo[i].mutex = &data->meals_mutex;
		data->philo[i].msg = &data->msg;
		i++;
	}
	return (0);
}

/*
1) Create mutex for printing in stdout.
2) If there is just 1 philo - call appropriate function and exit.
3) Create threads for each philosoppher.
Function ft_start starts the process of eating/sleeping/thinking.
*/
int	ft_create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.number)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
		&ft_start, &data->philo[i]))
			return (ft_error(5));
		i++;
	}
	return (0);
}
