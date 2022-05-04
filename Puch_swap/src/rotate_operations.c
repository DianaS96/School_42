/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:12:12 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:44:56 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
ra : rotate a - shift up all elements of stack a by 1. 
The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
*/
int	rotate(t_list **list_to_rotate)
{
	t_list	*tmp_first;
	t_list	*tmp;

	if ((*list_to_rotate) != NULL && (*list_to_rotate)->next != NULL)
	{
		tmp_first = (*list_to_rotate);
		(*list_to_rotate) = tmp_first->next;
		tmp = (*list_to_rotate);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = tmp_first;
		tmp_first->next = NULL;
		return (0);
	}
	return (-1);
}

void	ra(t_list **list_a)
{
	rotate(list_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **list_b)
{
	rotate(list_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	write(1, "rr\n", 3);
}
