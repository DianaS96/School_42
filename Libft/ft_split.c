/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:51:39 by coverand          #+#    #+#             */
/*   Updated: 2021/10/20 18:14:54 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*Allocates and returns an array of strings obtained by splitting ’s’ 
using the character ’c’ as a delimiter. 
The array must be ended by a NULL pointer.*/
/*Approach:
1) Count words (count_words);
2) Allocate memory to array, which will contain "count_words" items;
3) For each word count length, allocate memory in array for that len;
4) Fill array with words.*/
static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			i++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	count_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	free_arr(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(arr) * (count_words(s, c) + 1));
	if (arr == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c)
			j++;
		arr[i] = ft_substr(&s[j], 0, count_len(&s[j], c));
		if (arr[i] == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		j = j + count_len(&s[j], c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
