/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:52:14 by coverand          #+#    #+#             */
/*   Updated: 2021/10/19 18:48:35 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Outputs the integer ’n’ to the given file descriptor.*/
int	count(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	pw_10(int n)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < n)
	{
		result *= 10;
		i++;
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	ch;
	int		len;
	int		pwd;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	len = count(n);
	pwd = pw_10(len - 1);
	while (n > 9 || pwd >= 10)
	{
		ch = n / pwd + '0';
		write(fd, &ch, 1);
		n = n % pwd;
		pwd = pwd / 10;
	}
	ch = n + '0';
	write(fd, &ch, 1);
}
