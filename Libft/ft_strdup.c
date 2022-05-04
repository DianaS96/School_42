/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:51:16 by coverand          #+#    #+#             */
/*   Updated: 2021/10/15 18:19:07 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function copies string. Memory is allocated using malloc.*/
/*Return val - NULL if memory wasn't allocated.**
** Otherwise - pointer to duplicated string.*/
char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	i = ft_strlen(str);
	dest = (char *)malloc(sizeof(*dest) * i + 1);
	if (dest == 0)
		return (0);
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
