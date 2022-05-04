/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:10:32 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:37:01 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Allocates (with malloc(3)) and returns a new element.
The variable ’content’ is initialized with the value of ’content’.
The variable ’next’ is initialized to NULL.*/
t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == 0)
		return (NULL);
	list->data = content;
	list->order = 0;
	list->next = NULL;
	return (list);
}

/*Counts the number of elements in a list*/
int	ft_lstsize(t_list **lst)
{
	int		len;
	t_list	*tmp;

	tmp = (*lst);
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

/*Adds the element ’new’ at the beginning of the list.*/
/*We use temporary variable tmp to go througt list => we don't loose **lst*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*Free list*/
void	ft_lstdelete(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = NULL;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

int	list_is_sorted(t_list *list_a)
{
	t_list	*tmp;

	tmp = list_a;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
