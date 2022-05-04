/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:50:36 by coverand          #+#    #+#             */
/*   Updated: 2021/10/19 18:11:25 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function appends src to the end of dst.*/
/*Appends at most (dstsize - strlen(dst)i - 1)*/
/*Return value = total length of the string that we would get*/
/*(dst + len_dst) in ft_memcpy means that we copy at the end of dst. */
/*iIf the return value is >= dstsize, the output string has been truncated.*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	min_len_dst;
	size_t	j;

	j = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	min_len_dst = len_src + dstsize;
	if (dstsize > len_dst)
		min_len_dst = len_src + len_dst;
	if (dstsize <= len_dst)
		return (min_len_dst);
	while (len_dst + 1 < dstsize && src[j])
	{
		dst[len_dst] = src[j];
		len_dst++;
		j++;
	}
	dst[len_dst] = '\0';
	return (min_len_dst);
}
