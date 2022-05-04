/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:33:29 by coverand          #+#    #+#             */
/*   Updated: 2022/01/11 14:58:56 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

/*Function outputs the string ’s’ to the given file descriptor.*/
void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(0, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	char	ch;

	if (n == -2147483648)
	{
		write(0, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(0, "-", 1);
		n = -n;
	}
	while (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ch = n + '0';
	write(0, &ch, 1);
}

int	ft_check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
