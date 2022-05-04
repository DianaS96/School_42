/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:48:47 by coverand          #+#    #+#             */
/*   Updated: 2021/10/19 15:27:07 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function returns a pointer to the LAST occurrence** 
**of specified character in string.*/
/*The function returns NULL if the specified character is not found.*/
char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if ((char) str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
