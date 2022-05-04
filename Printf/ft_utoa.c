/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:07:18 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 18:08:33 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Approach:
1) Find number of digits in u int
2) Allocate memory to str.
3) Write each digit in string.*/
static int	count_dig(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
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

char	*ft_utoa(unsigned int n)
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
	k = ft_power10(num_of_digits - 1 - i);
	while (i < num_of_digits)
	{
		str[i++] = n / k + '0';
		n = n % k;
		k /= 10;
	}
	str[i] = '\0';
	return (str);
}
