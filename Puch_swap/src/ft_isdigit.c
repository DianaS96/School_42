/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:43:56 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 14:43:58 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_isdigit returns 1 if character is a digit.*/
/* If not, it returns 0*/
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
