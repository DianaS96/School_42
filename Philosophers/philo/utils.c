/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:09:40 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 16:57:21 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_clean(t_data *data)
{
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
}

int	ft_join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input.number)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (ft_error(7));
		i++;
	}
	return (0);
}

int	ft_print_action(char *msg, unsigned long time, t_philo *philo)
{
	pthread_mutex_lock(philo->msg);
	if (time == 0)
		printf(msg, get_time() - philo->input->start_time, philo->id);
	else
		printf(msg, time, philo->id);
	pthread_mutex_unlock(philo->msg);
	return (0);
}
