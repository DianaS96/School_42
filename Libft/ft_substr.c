/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:48:14 by coverand          #+#    #+#             */
/*   Updated: 2021/10/19 20:33:16 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’*/
/*1. Count len_sub (from i to i + len or from i to end of string.
2. Allocate memory.
3. Fill substring.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*substr;

	i = 0;
	len_s = ft_strlen(s);
	if (len > len_s - i)
		len = len_s - i;
	if (start > len_s)
		len = 0;
	substr = (char *)malloc(sizeof(char) * (len) + 1);
	if (substr == 0)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
