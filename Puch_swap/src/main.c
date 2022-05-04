/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:10:55 by coverand          #+#    #+#             */
/*   Updated: 2022/01/07 19:39:45 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*
1) Check validity of arguments
2) Call sorting function
If number of items to sort > 6 => use radix sort
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
*/

void	ft_sort(t_list **list_a, t_list **list_b, int count_nums)
{
	if (count_nums == 2)
		sa(list_a);
	else if (count_nums == 3)
		sort_three_elements(list_a);
	else if (count_nums == 4)
		sort_four_elements(list_a, list_b);
	else if (count_nums == 5)
		sort_five_elements(list_a, list_b);
	else if (count_nums == 6)
		sort_six_elements(list_a, list_b);
	else
	{
		simplify_nums(list_a, list_b);
		radix_sort(list_a, list_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return (0);
	check_arguments(argc, argv, &list_a);
	if (list_is_sorted(list_a) == 0)
	{
		ft_lstdelete(&list_a);
		ft_lstdelete(&list_b);
		return (0);
	}
	ft_sort(&list_a, &list_b, (argc - 1));
	ft_lstdelete(&list_a);
	ft_lstdelete(&list_b);
	return (0);
}
