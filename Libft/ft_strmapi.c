/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:49:33 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 14:49:34 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applies the function ’f’ to each character of the
string ’s’ to create a new string (with malloc(3))
resulting from successive applications of ’f’.
Return value - The string created from the successive applications of ’f’. 
Returns NULL if the allocation fails.*/
/*"char (*f)(unsigned int, char)" a function pointer f to a function
that accepts a UI&char and returns a char.
Without the parens around *f we would be declaring a function f
 that returns a POINTER to char.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(*new_str) * ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
