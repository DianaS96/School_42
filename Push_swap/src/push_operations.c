/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:11:40 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:43:00 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
pa : take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb : take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
int	execute_push(t_list **list_to, t_list **list_from)
{
	t_list	*tmp_first_from;
	t_list	*copy_list_to;

	if (!(*list_from))
		return (-1);
	tmp_first_from = (*list_from);
	(*list_from) = tmp_first_from->next;
	copy_list_to = (*list_to);
	(*list_to) = tmp_first_from;
	(*list_to)->next = copy_list_to;
	return (0);
}

void	pa(t_list **list_a, t_list **list_b)
{
	int	i;

	i = execute_push(list_a, list_b);
	if (i == 0)
		write(1, "pa\n", 3);
}

void	pb(t_list **list_a, t_list **list_b)
{
	int	i;

	i = execute_push(list_b, list_a);
	if (i == 0)
		write(1, "pb\n", 3);
}
