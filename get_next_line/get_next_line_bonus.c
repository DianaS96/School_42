/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:40:45 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 15:44:13 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*BUFFER_SIZE - amount of symbols that we read in buf*/
/*Overall approach: 
1. We read text from fd to buf.
2. If we have '\n' in buf, we put everything from buf to line.
3. Else if there is nothing to read from fd => 
write everything from buf in line and free(buf).
4. Else - p. 1.*/

/*ft_search_nl
1. Count symbols till '\n' or '\0' and return this number.
*/
size_t	ft_search_nl(char *result)
{
	size_t	i;

	i = 0;
	while (result[i] != '\n' && result[i])
		i++;
	return (i);
}

/*ft_cut_str:
1) cuts the incoming string til the '\n' (if '\n' exists)
2) returns the resulting shortened string
We allocate to new_str (i + 2) symbols:
* i - number of characters in remainder till '/n' ('\n' not included);
* 1 char for '\n';
* 1 char for '\0';
*/
char	*ft_cut_str(char *rem)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = ft_search_nl(rem);
	j = 0;
	new_str = malloc(sizeof(*new_str) * (i + 2));
	if (!new_str)
		return (NULL);
	while (j <= i)
	{
		new_str[j] = rem[j];
		j++;
	}
	new_str[j] = '\0';
	if (new_str[0] == 0)
	{
		free(new_str);
		return (0);
	}
	return (new_str);
}

/*
1) Find number of symbols in remainder before '\0' or '\n'
2) Create new string, where you put all symbols after '\n' in remainder:
len(rem_new) = len(old_rem) - len(string till '/n' or '/0');
3) Return new string*/
char	*ft_cut_rem(char *rem)
{
	size_t		i;
	size_t		j;
	char		*rem_new;

	if (!rem)
		return (NULL);
	i = ft_search_nl(rem);
	if (rem[i] == '\0')
	{
		free(rem);
		return (NULL);
	}
	rem_new = malloc(sizeof(*rem_new) * (ft_strlen(rem) - i));
	if (!rem_new)
	{
		free(rem);
		return (NULL);
	}
	j = 0;
	i++;
	while (rem[i])
		rem_new[j++] = rem[i++];
	rem_new[j] = '\0';
	free(rem);
	return (rem_new);
}

/*
get_next_line.c:
1) Check validity of fd and BUFFER_SIZE;
2) Copy info from fd to buf and then from buf to rem;
If fd is closed or empty, we exit.
3) Call function that returns string to return in get_next_line function;
4) Call function that updates remainder (cuts rem from the beginning till '\n');
5) Return needed line;
*/
char	*get_next_line(int fd)
{
	char		*result;
	char		buf[BUFFER_SIZE + 1];
	static char	*rem[OPEN_MAX];
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = -1;
	while (len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = '\0';
		rem[fd] = ft_strjoin_modified(rem[fd], buf, len);
		if (ft_strchr(rem[fd], '\n') != 0)
			break ;
	}
	if (!rem[fd])
		return (NULL);
	result = ft_cut_str(rem[fd]);
	rem[fd] = ft_cut_rem(rem[fd]);
	return (result);
}
