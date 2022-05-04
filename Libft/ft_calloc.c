/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:42:44 by coverand          #+#    #+#             */
/*   Updated: 2021/10/15 18:04:57 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_calloc allocates memory for an array of num objects of size
and initializes all bytes in the allocated storage to zero.
If Ok, returns a pointer to the first byte in the allocated memory block.
Else, null pointer is returned*/
void	*ft_calloc(size_t num, size_t size)
{
	void	*dest;

	dest = malloc(num * size);
	if (dest == 0)
		return (0);
	ft_bzero(dest, num * size);
	return ((void *)dest);
}
