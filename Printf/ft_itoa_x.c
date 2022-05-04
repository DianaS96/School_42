/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:17:54 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 18:09:27 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_x_help(unsigned long n, int capital, int count, char *str);

/*
Count number of digits in hexadecimal number.
*/
static int	ft_num_of_digits(unsigned long tmp)
{	
	int	num_of_digits;

	num_of_digits = 0;
	if (tmp == 0)
		return (1);
	while (tmp != 0)
	{
		tmp = tmp / 16;
		num_of_digits++;
	}
	return (num_of_digits);
}

/*
1) Count number of digits in hexadecimal number;
2) Allocate memory for the string representing number;
3) Form array of chars from the last to the first item using 
function "ft_itoa_x_help";
4) Return string that contains hexadecimal number.
*/
char	*ft_itoa_x(unsigned long n, int capital)
{
	int				num_of_digits;
	char			*str;

	num_of_digits = ft_num_of_digits(n);
	str = malloc(sizeof(*str) * num_of_digits + 1);
	if (!str)
		return (NULL);
	str[num_of_digits--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str = ft_itoa_x_help(n, capital, num_of_digits, str);
		n = n / 16;
		num_of_digits--;
	}
	return (str);
}

static char	*ft_itoa_x_help(unsigned long n, int capital, int count, char *str)
{
	if (n % 16 >= 10)
	{
		if (capital == 0)
			str[count] = n % 16 + 87;
		else if (capital == 1)
			str[count] = n % 16 + 55;
	}
	else
		str[count] = n % 16 + '0';
	return (str);
}
