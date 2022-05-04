/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:49:17 by coverand          #+#    #+#             */
/*   Updated: 2022/04/09 18:39:35 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_error(int i)
{
	if (i == 1)
		printf(FRED"Wrong number of args.\nUsage: number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n"NONE);
	else if (i == 2)
		printf(FRED"Memory was not allocated."NONE);
	else if (i == 3)
		printf(FRED"Inputs should be positive integers."NONE);
	else if (i == 4)
		printf(FRED"Smth is wrong with time."NONE);
	else if (i == 5)
		printf(FRED"Thread was not created."NONE);
	else if (i == 6)
		printf(FRED"Mutex was not created."NONE);
	else if (i == 7)
		printf(FRED"Smth is wrong with joining threads."NONE);
	return (1);
}
