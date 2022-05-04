/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:20:13 by coverand          #+#    #+#             */
/*   Updated: 2021/11/29 18:36:02 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
#endif*/

char	*get_next_line(int fd);

char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin_modified(char const *s1, char const *s2, int len2);
#endif
