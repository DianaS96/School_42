/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:52:09 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 17:42:12 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function outputs the string ’s’*/
int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char ch)
{
	return (write(1, &ch, sizeof(ch)));
}

/*
1) Type definition;
2) Calling function to print argument depending on its type;
3) Returning length of printed argument.*/
int	process_type(char type, va_list arguments)
{
	int	length;

	length = 0;
	if (type == 'c')
		return (ft_print_c(va_arg(arguments, unsigned int)));
	if (type == 's')
		return (ft_print_s(va_arg(arguments, char *)));
	if (type == 'i' || type == 'd')
		return (ft_print_id(va_arg(arguments, int)));
	if (type == 'u')
		return (ft_print_u(va_arg(arguments, unsigned int)));
	if (type == 'x')
		return (ft_print_x(va_arg(arguments, unsigned int), 0));
	if (type == 'X')
		return (ft_print_x(va_arg(arguments, unsigned int), 1));
	if (type == 'p')
		return (ft_print_p(va_arg(arguments, unsigned long long)));
	if (type == '%')
		return (ft_print_perc());
	return (length);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
