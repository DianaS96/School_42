/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:53:38 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 14:53:40 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Function outputs the character ’c’ to the given file descriptor.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
