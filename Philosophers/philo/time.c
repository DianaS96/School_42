/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:11:01 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 16:43:49 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"
#include <stdio.h>

unsigned long	get_time(void)
{
	struct timeval	cur_time;

	if (gettimeofday(&cur_time, NULL) != 0)
		return (-1);
	return (cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000);
}

void	ft_sleep(unsigned long ms)
{
	long	start;

	start = get_time();
	while ((long)get_time() - start < (long)ms)
		usleep(10);
}
