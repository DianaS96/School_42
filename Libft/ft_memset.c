/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:53:07 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 14:53:09 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function fills the first n bytes in destination with symbol c.**
**If number of chars to be replaced is greater than length of dest,**
the behaviour is undefined*/
void	*ft_memset(void *dest, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	i = 0;
	while (n > 0)
	{
		ptr[i] = c;
		i++;
		n--;
	}
	return (dest);
}
