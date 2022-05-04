/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:11:54 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:51:48 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Box A - for keeping numbers with digit 1.
Box B - for keeping numbers with digit 0.

Steps:
1) Find max number of bits

2) Compare digits (binary system) of each number with 1 and 0. 
If we have number with i-th digit 0 in A -> make pb operation;
If we have number with i-th digit 1 in A -> make ra operation;

3) If there is no more numbers with i-th digit 0 in A -> 
make pa till there is no items in B.
*/

static int	readix_sort_help(t_list **list_a, t_list **list_b, int i);

void	radix_sort(t_list **list_a, t_list **list_b)
{
	int	len_bit;
	int	size;
	int	i;
	int	j;
	int	flag;

	i = 0;
	size = ft_lstsize(list_a) - 1;
	len_bit = 0;
	while ((size >> len_bit) != 0)
		len_bit++;
	while (i < len_bit)
	{
		j = 0;
		while (j <= size)
		{
			flag = readix_sort_help(list_a, list_b, i);
			if (flag == 0)
				break ;
			j++;
		}
		i++;
		while (*list_b)
			pa(list_a, list_b);
	}
}

static int	readix_sort_help(t_list **list_a, t_list **list_b, int i)
{
	if ((list_is_sorted(*list_a)) == 0)
		return (0);
	if ((((*list_a)->order >> i) & 1) == 1)
		ra(list_a);
	else
		pb(list_a, list_b);
	return (1);
}
