/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:48:31 by coverand          #+#    #+#             */
/*   Updated: 2021/10/20 18:17:12 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Function allocates and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/
static int	chek_beginning(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (s1[i])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				flag++;
			j++;
		}
		if (flag == 0)
			break ;
		i++;
	}
	return (i);
}

static int	chek_end(char const *s1, char const *set, int len, int i)
{
	int	flag;
	int	j;

	while (len - 1 > i)
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[len - 1] == set[j])
				flag++;
			j++;
		}
		if (flag == 0)
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	i = chek_beginning(s1, set);
	len = chek_end(s1, set, ft_strlen(s1), i);
	result = malloc(sizeof(char) * (len - i) + 1);
	if (result == 0)
		return (0);
	j = 0;
	while (i <= len - 1)
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
