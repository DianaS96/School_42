/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:12:55 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:46:12 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//# include <stdio.h>

typedef struct s_struct
{
	int				data;
	int				order;
	struct s_struct	*next;
}	t_list;

int		ft_strlen(const char *str);
int		ft_isdigit(int c);

/* File check_arg.c*/
int		check_arguments(int argc, char **argv, t_list **list_a);
void	print_error(void);

/* File ft_atoi.c*/
int		ft_atoi(const char *str);

/* File list.c*/
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelete(t_list **lst);
int		list_is_sorted(t_list *list_a);

/*File swap_operations.c*/
int		swap(t_list **list);
void	sa(t_list **list_a);
void	sb(t_list **list_b);
void	ss(t_list **list_a, t_list **list_b);

/*File push_operations.c*/
int		execute_push(t_list **list_to, t_list **list_from);
void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);

/*File rotate_operations.c*/
int		rotate(t_list **list_to_rotate);
void	ra(t_list **list_a);
void	rb(t_list **list_b);
void	rr(t_list **list_a, t_list **list_b);

/*File rev_rotate_operations.c*/
void	rra(t_list **list_a);
void	rrb(t_list **list_b);
void	rrr(t_list **list_a, t_list **list_b);

/*File mini_sort.c*/
void	sort_three_elements(t_list **list_a);
void	sort_four_elements(t_list **list_a, t_list **list_b);
void	sort_five_elements(t_list **list_a, t_list **list_b);
void	sort_six_elements(t_list **list_a, t_list **list_b);

/*File min_max_mid_find.c*/
int		find_min(t_list **list);
int		find_max(t_list **list);

/*File simplify_nums.c*/
void	simplify_nums(t_list **list_a, t_list **list_b);

/*File radix_sort.c*/
void	radix_sort(t_list **list_a, t_list **list_b);

#endif
