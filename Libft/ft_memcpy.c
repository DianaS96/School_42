/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:52:55 by coverand          #+#    #+#             */
/*   Updated: 2021/10/16 19:18:49 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function copies block of memory from src to dest.*/
/*Both dest and src arguments are arrays of unsigned char.*/
/*The behaiviour is undefined if n > len(dest).*/
void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char		*dest;
	const char	*src;
	int			i;

	i = 0;
	dest = destination;
	src = source;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (destination);
}
