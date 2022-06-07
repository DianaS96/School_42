/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:12:21 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:52:44 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_array(t_list **list_a, int size, int *arr_sort, int *arr_pos);
static void	sort_array(int	*array_sorted, int size);
static void	simplify_help(int *arr_sort, int *arr_pos, int len, t_list **a);
static void	lst_add_order(int *arr_pos, int *arr_sort, int len, t_list **lst_a);

/*
Before radix sort we should simplify list of integers
to make them in range [0; len), where len is size of list.

simplify_nums function:
1) allocate memory for 2 arrays;
2) call function fill_array that fills these arrays with input numbers
3) call function simplify_help that simplifies numbers
*/
void	simplify_nums(t_list **list_a, t_list **list_b)
{
	int		*array_sorted;
	int		*array_posit;
	int		size;

	size = ft_lstsize(list_a);
	array_sorted = malloc(sizeof(int) * size);
	if (!array_sorted)
	{
		ft_lstdelete(list_a);
		ft_lstdelete(list_b);
		exit(EXIT_FAILURE);
	}
	array_posit = malloc(sizeof(int) * size);
	if (!array_posit)
	{
		free(array_sorted);
		ft_lstdelete(list_a);
		ft_lstdelete(list_b);
		exit(EXIT_FAILURE);
	}
	fill_array(list_a, size, array_sorted, array_posit);
	simplify_help(array_sorted, array_posit, size, list_a);
}

/*Function that fill 2 arrays with input numbers*/
static void	fill_array(t_list **list_a, int size, int *arr_sort, int *arr_pos)
{
	t_list	*tmp;
	int		i;

	tmp = *list_a;
	i = 0;
	while (i < size)
	{
		arr_sort[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < size)
	{
		arr_pos[i] = arr_sort[i];
		i++;
	}
	sort_array(arr_sort, size);
}

/*Function that sorts numbers*/
static void	sort_array(int	*array_sorted, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array_sorted[i] > array_sorted[j])
			{
				tmp = array_sorted[i];
				array_sorted[i] = array_sorted[j];
				array_sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	simplify_help(int *arr_sort, int *arr_pos, int len, t_list **a)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr_pos[i] == arr_sort[j])
			{
				arr_pos[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	lst_add_order(arr_pos, arr_sort, len, a);
}

static void	lst_add_order(int *arr_pos, int *arr_sort, int len, t_list **lst_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst_a;
	while (i < len)
	{
		tmp->order = arr_pos[i];
		tmp = tmp->next;
		i++;
	}
	free(arr_sort);
	free(arr_pos);
}
