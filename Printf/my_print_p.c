/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:51:53 by coverand          #+#    #+#             */
/*   Updated: 2021/11/29 20:57:44 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Count number of symbols in ptr that will be printed*/
static int	ptr_count_digits(unsigned long long tmp)
{
	int	count;

	count = 0;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		count++;
	}
	return (count);
}

/*Create string that contain ptr in hexadecimal. 
Memory for str is allocated using malloc. */
static char	*ptr_create_str(unsigned long long n)
{
	int					count;
	char				*str;

	count = ptr_count_digits(n);
	str = malloc(sizeof(*str) * (count + 1));
	if (!str)
		return (0);
	str[count--] = '\0';
	while (n != 0)
	{
		if (n % 16 >= 10)
			str[count] = n % 16 + 87;
		else
			str[count] = n % 16 + '0';
		count--;
		n = n / 16;
	}
	return (str);
}

int	ft_print_p(unsigned long long n)
{
	int				length;
	char			*str;

	length = 0;
	if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
		str = ptr_create_str(n);
	length = 2 + ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, ft_strlen(str));
	free(str);
	return (length);
}
