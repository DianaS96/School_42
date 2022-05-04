/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:48:38 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 17:21:31 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
1. If precision > len(str) -> we should print the whole string;
2. If we have '-':
- if we have precision
- Otherwise - just print the string
*/
int	ft_print_s(char *str)
{
	int	length;
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}
