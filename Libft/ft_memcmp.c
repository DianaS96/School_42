/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:52:45 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 14:52:46 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Return value:
0 - if compared parts of arrays are identical;
int > 0 - if arr1[i] > arr2[i];
int < 0 - if arr1[i] < arr2[i];
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	i = 0;
	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (arr1[i] != arr2[i])
			return ((unsigned char)arr1[i] - (unsigned char)arr2[i]);
		i++;
	}
	return (0);
}
