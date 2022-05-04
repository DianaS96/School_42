/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:48:19 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 17:49:17 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int n)
{
	int		length;
	char	*str;

	length = 0;
	str = ft_utoa(n);
	length = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (length);
}
