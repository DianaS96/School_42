/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_mid_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:11:19 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:45:47 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_list **list)
{
	int		min;
	t_list	*tmp;

	tmp = (*list);
	min = tmp->data;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_list **list)
{
	int		max;
	t_list	*tmp;

	tmp = (*list);
	max = tmp->data;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}
