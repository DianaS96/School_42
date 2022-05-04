/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:17:01 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 17:54:33 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
types:
• %c print a single character.
• %s print a string of characters.
• %p The void * pointer argument is printed in hexadecimal.
• %d print a decimal (base 10) number.
• %i print an integer in base 10.
• %u print an unsigned decimal (base 10) number.
• %x print a number in hexadecimal (base 16), with lowercase.
• %X print a number in hexadecimal (base 16), with uppercase.
• %% print a percent sign.
*/
int	check_type(char s)
{
	if (s == 'c' || s == 's' || s == 'p'\
		|| s == 'd' || s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}
