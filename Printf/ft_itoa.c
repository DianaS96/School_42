/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:17:23 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 17:55:26 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Return value: 
The string representing the integer. 
NULL if the allocation fails.*/
/*Allocates and returns a string representing the int received as an argument.
Negative numbers must be handled.*/
/*Approach:
1) Find number of digits and sings (-) in int
2) Allocate memory to str.
3) Write each digit in string.
4) If string is negative - write '-', then go to p.3*/
static int	count_dig(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		if (n == -2147483648)
		{
			i = 2;
			n = -147483648;
		}
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_power10(int n)
{
	int	k;

	k = 1;
	while (n > 0)
	{
		k = k * 10;
		n--;
	}
	return (k);
}

static void	negative_numbers(int n, char *str, int num_of_digits, int i)
{
	int	k;

	str[i++] = '-';
	if (n == -2147483648)
	{
		str[i++] = '2';
		n = -147483648;
	}
	n = -n;
	k = ft_power10(num_of_digits - 1 - i);
	while (i < num_of_digits)
	{
		str[i++] = n / k + '0';
		n = n % k;
		k /= 10;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		num_of_digits;
	char	*str;
	int		i;
	int		k;

	i = 0;
	num_of_digits = count_dig(n);
	str = malloc(sizeof(*str) * num_of_digits + 1);
	if (str == 0)
		return (0);
	if (n < 0)
		negative_numbers(n, str, num_of_digits, i);
	else
	{
		k = ft_power10(num_of_digits - 1 - i);
		while (i < num_of_digits)
		{
			str[i++] = n / k + '0';
			n = n % k;
			k /= 10;
		}
		str[i] = '\0';
	}
	return (str);
}
