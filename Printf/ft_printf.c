/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:18:17 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 19:51:27 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*ft_printf:
1) initialize length (it will be length of printed bytes in the end)
2) initialize va_list using va_start
3) call parser function that returns length
4) return length of printed bytes*/
int	ft_printf(const char *arg, ...)
{
	int		length;
	va_list	arguments;

	length = 0;
	va_start(arguments, arg);
	length = parse_input(arg, arguments);
	va_end(arguments);
	return (length);
}

/*
1) Print chars til '%'
2) Check whether we have type indicator after '%':
- if we have type indicator or '%' after '%', call relevant function;
- else - exit from the function;

Return value - length of printed chars.
*/
int	parse_input(const char *arg, va_list arguments)
{
	int		length;
	int		i;
	char	type;

	length = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '%' && arg[i + 1])
		{
			i++;
			if (check_type(arg[i]) == 1)
			{
				type = arg[i];
				length += process_type(type, arguments);
			}
		}
		else if (arg[i] == '\0' || (arg[i] == '%' && !arg[i + 1]))
			return (length);
		else if (arg[i])
			length += ft_putchar(arg[i]);
		i++;
	}
	return (length);
}
