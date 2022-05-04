/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:47:29 by coverand          #+#    #+#             */
/*   Updated: 2021/11/29 19:53:36 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int n, int capital)
{
	int		length;
	char	*str;

	length = 0;
	n = (unsigned long)n;
	str = ft_itoa_x(n, capital);
	length = ft_strlen(str);
	write(1, str, length);
	free(str);
	return (length);
}
