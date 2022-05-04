/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:02:34 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 19:01:48 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

/*Returns value of integer from a string.*/
/*If there is no digits in string - return 0.*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

/* Check that argument contains only spaces, sign and digits.*/
static int	check_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ' || arg[i] == '\f' || arg[i] == '\n'
		|| arg[i] == '\r' || arg[i] == '\t' || arg[i] == '\v')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

/*
MIN_INT −2,147,483,648 (11 symbols)
MAX_INT 2,147,483,647 (10 symbols)
*/
static int	check_num_is_int(char *arg)
{
	int	i;
	int	len;
	int	number;

	i = 0;
	len = ft_strlen(arg);
	while (arg[i] == ' ' || arg[i] == '\f' || arg[i] == '\n'
		|| arg[i] == '\r' || arg[i] == '\t' || arg[i] == '\v')
		i++;
	if (len - i > 11)
		return (-1);
	number = ft_atoi(arg);
	if (arg[i] == '-' && number > 0)
		return (-1);
	else if (number < 0 && arg[i] != '-')
		return (-1);
	if (number < 0)
		return (-1);
	return (0);
}

/*
1) number_of_philosophers t
2) time_to_die 
3) time_to_eat 
4) time_to_sleep
5) [number_of_times_each_philosopher_must_eat]
*/
int	check_arguments(int argc, char **argv, t_data *data)
{
	int	arg;

	arg = 1;
	while (arg < argc)
	{
		if (check_num(argv[arg]) == -1 || check_num_is_int(argv[arg]) == -1)
			return (ft_error(3));
		arg++;
	}
	data->input.number = ft_atoi(argv[1]);
	data->input.t_die = ft_atoi(argv[2]);
	data->input.t_eat = ft_atoi(argv[3]);
	data->input.t_sleep = ft_atoi(argv[4]);
	data->input.min_eat = -1;
	if (data->input.number <= 0 || data->input.t_die <= 0 || \
		data->input.t_eat <= 0 || data->input.t_sleep <= 0)
		return (ft_error(3));
	if (argc == 6)
	{
		data->input.min_eat = ft_atoi(argv[5]);
		if (data->input.min_eat <= 0)
			return (ft_error(3));
	}
	data->input.start_time = get_time();
	return (0);
}
