/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:12:03 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:45:10 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
rra : reverse rotate a - shift down all elements of stack a by 1.
The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
static int	rev_rotate(t_list **list_to_rotate)
{
	t_list	*tmp_first;
	t_list	*tmp;

	if ((*list_to_rotate) != NULL && (*list_to_rotate)->next != NULL)
	{
		tmp_first = (*list_to_rotate);
		tmp = (*list_to_rotate);
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		(*list_to_rotate) = tmp->next;
		(*list_to_rotate)->next = tmp_first;
		tmp->next = NULL;
		return (0);
	}
	return (-1);
}

void	rra(t_list **list_a)
{
	rev_rotate(list_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **list_b)
{
	rev_rotate(list_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rev_rotate(list_a);
	rev_rotate(list_b);
	write(1, "rrr\n", 4);
}
