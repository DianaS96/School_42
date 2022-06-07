/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:12:34 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:39:51 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sa : swap a - swap the first 2 elements at the top of stack a. 
Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. 
Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
*/
int	swap(t_list **list)
{
	int	tmp;

	if (!(*list) || !(*list)->next)
		return (-1);
	tmp = (*list)->data;
	(*list)->data = (*list)->next->data;
	(*list)->next->data = tmp;
	return (0);
}

void	sa(t_list **list_a)
{
	int	i;

	i = swap(list_a);
	if (i == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **list_b)
{
	int	i;

	i = swap(list_b);
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **list_a, t_list **list_b)
{
	int	i;
	int	j;

	i = swap(list_a);
	j = swap(list_b);
	if (i == 0 || j == 0)
		write(1, "ss", 3);
}
