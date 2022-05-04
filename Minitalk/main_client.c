/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:30:38 by coverand          #+#    #+#             */
/*   Updated: 2022/01/12 15:38:50 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg_help(int pid, int counter, char ch);

static void	send_message(int pid, char *str)
{
	int		counter;
	int		i;
	int		len;
	char	ch;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (i < len)
			ch = str[i];
		else
			ch = '\0';
		counter = 128;
		while (counter >= 1)
		{
			send_msg_help(pid, counter, ch);
			counter /= 2;
			usleep(600);
		}
		i++;
	}
}

static void	send_msg_help(int pid, int counter, char ch)
{
	int	kill_status;

	if ((ch & counter) > 0)
		kill_status = kill(pid, SIGUSR1);
	else
		kill_status = kill(pid, SIGUSR2);
	if (kill_status == -1)
	{
		ft_putstr(FRED"Signal was not sent."NONE);
		exit(EXIT_FAILURE);
	}	
}

/*
 * pid - SERVER's PID that we get after running server program
 1) If num of args is not 3 => exit;
 2) Convert server's PID to int;
 3) Iterate through each char in string that should be send to client (argv[2]).
 For each character we should send 8 bits via SIGUSR1 (1) and SIGUSR2 (0).
 To send a signal to specified processes or process groups use kill command.
 4) Function usleep() is used for job delaying
 (in case of using usleep functions will not be lost) 
 */
int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr(FRED"Incorrect number of arguments.\n"NONE);
		ft_putstr(FRED"Usage: ./client [server PID] [message]\n"NONE);
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) < 0 || ft_check_pid(argv[1]) < 0)
	{
		ft_putstr(FRED"Incorrect PID\n"NONE);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
