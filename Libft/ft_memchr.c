/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:56:14 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 15:43:30 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Arguments:
arr - pointer to array, in which we will search specific symbol c;
c - code of the character we are looking for;
n - size of array's part (in which we will look for c).
Return value: 
NULL - if we didn't find symbol;
Otherwise - pointer to the symbol in array. */
void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t		i;
	const char	*src;

	i = 0;
	src = arr;
	while (i < n)
	{
		if ((char)src[i] == (char)c)
			return ((void *)&src[i]);
		i++;
	}
	return (0);
}
