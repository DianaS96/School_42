/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:02:28 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 18:11:31 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (ft_error(1));
	if (check_arguments(argc, argv, &data))
		return (1);
	if (ft_init_philos(&data) || ft_init_forks(&data))
		return (1);
	ft_create_thread(&data);
	if (ft_check_dead(&data) == 1)
	{
		pthread_mutex_unlock(&data.msg);
		pthread_mutex_destroy(&data.msg);
		pthread_mutex_destroy(&data.meals_mutex);
		ft_clean(&data);
		return (0);
	}
	return (0);
}
