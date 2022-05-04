/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:49:52 by coverand          #+#    #+#             */
/*   Updated: 2021/11/29 19:50:02 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_id(int n)
{
	int		length;
	char	*str;

	length = 0;
	str = ft_itoa(n);
	length = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (length);
}
