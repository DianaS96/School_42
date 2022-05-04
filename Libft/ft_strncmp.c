/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:49:21 by coverand          #+#    #+#             */
/*   Updated: 2021/10/19 18:12:18 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function returns:
Int less than 0 if str1 < str2;
0 if str1 == str2;
Int greater than 0 if str1 > str2.
The function compares the first n bytes in str1 & str2.*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (str1[i] == '\0' && i != 0 && i == n)
		i--;
	if (i == n)
		i--;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
