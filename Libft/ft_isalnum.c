/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:43:01 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 14:43:06 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns 1 if character is alphabetical or numerical.*/
/*If not, it returns 0*/
int	ft_isalnum(int c)
{
	if (c < '0' || (c > '9' && c < 'A') || \
		(c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}
