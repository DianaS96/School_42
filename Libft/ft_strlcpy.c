/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:50:27 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 16:08:34 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function copies "size" characters from src to dst, 
NUL-terminating the result.*/
/*Return value - total length of the src.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = ft_strlen(src);
	if (size == 0)
		return (length);
	if (length + 1 < size)
	{
		ft_memcpy(dst, src, length + 1);
	}
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (length);
}
