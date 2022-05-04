/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:46:18 by coverand          #+#    #+#             */
/*   Updated: 2021/10/14 14:46:20 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a new element.
The variable ’content’ is initialized with the value of ’content’.
The variable ’next’ is initialized to NULL.*/

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == 0)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
