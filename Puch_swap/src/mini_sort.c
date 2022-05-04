/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:11:28 by coverand          #+#    #+#             */
/*   Updated: 2022/01/07 19:11:30 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Cases for 3 nums:
1) 123 - see main;
2) 132 => rra, sa;
3) 231 => rra;
4) 213 => sa;
5) 321 => ra, sa;
6) 312 => ra;
*/
void	sort_three_elements(t_list **list_a)
{
	if ((*list_a)->next->data > (*list_a)->next->next->data && \
		(*list_a)->next->next->data > (*list_a)->data)
	{
		rra(list_a);
		sa(list_a);
	}
	else if ((*list_a)->next->data > (*list_a)->data && \
		(*list_a)->next->next->data < (*list_a)->data)
		rra(list_a);
	else if ((*list_a)->next->next->data > (*list_a)->data && \
		(*list_a)->data > (*list_a)->next->data)
		sa(list_a);
	else if ((*list_a)->data > (*list_a)->next->data && \
		(*list_a)->next->data > (*list_a)->next->next->data)
	{
		ra(list_a);
		sa(list_a);
	}
	else if ((*list_a)->data > (*list_a)->next->next->data && \
		(*list_a)->next->next->data > (*list_a)->next->data)
		ra(list_a);
}

/*
1) Find min value, rotate list_a till min value is on the top of list_a;
2) Push min value to list_b;
3) Sort 3 vals in list_a;
4) Push min value back to list_a
*/
void	sort_four_elements(t_list **list_a, t_list **list_b)
{
	int		min;
	int		i;
	t_list	*tmp;

	i = 0;
	min = find_min(list_a);
	tmp = (*list_a);
	while (tmp->data != min)
	{
		tmp = tmp->next;
		i++;
	}
	while ((*list_a)->data != min)
	{
		if (i < 2)
			ra(list_a);
		else
			rra(list_a);
	}
	pb(list_a, list_b);
	if (list_is_sorted(*list_a) == -1)
		sort_three_elements(list_a);
	pa(list_a, list_b);
}

/*
1) Find min value, rotate list_a till min value is on the top of list_a;
2) Push min value to list_b;
3) Call sort_four_elements 
4) Push 1 num from list_b to list_a
*/
void	sort_five_elements(t_list **list_a, t_list **list_b)
{
	int		min;
	int		i;
	t_list	*tmp;

	i = 0;
	min = find_min(list_a);
	tmp = (*list_a);
	while (tmp->data != min)
	{
		tmp = tmp->next;
		i++;
	}
	while ((*list_a)->data != min)
	{
		if (i < 3)
			ra(list_a);
		else
			rra(list_a);
	}
	pb(list_a, list_b);
	if (list_is_sorted(*list_a) == -1)
		sort_four_elements(list_a, list_b);
	pa(list_a, list_b);
}

/*
1) While number of items in list_a is not 3:
- find min in list_a
- push min to list_b
2) sort list_a
3) pa all items from list_b
*/
void	sort_six_elements(t_list **list_a, t_list **list_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while ((ft_lstsize(list_a)) != 3)
	{
		tmp = (*list_a);
		while (tmp->data != find_min(list_a))
		{
			tmp = tmp->next;
			i++;
		}
		while ((*list_a)->data != find_min(list_a))
		{
			if (i < 3)
				ra(list_a);
			else
				rra(list_a);
		}
		pb(list_a, list_b);
	}
	sort_three_elements(list_a);
	while (ft_lstsize(list_b))
		pa(list_a, list_b);
}
