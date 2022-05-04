/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:09:59 by coverand          #+#    #+#             */
/*   Updated: 2022/01/13 15:33:04 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/* Check that argument contains only spaces, sign and digits.*/
static int	check_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ' || arg[i] == '\f' || arg[i] == '\n'
		|| arg[i] == '\r' || arg[i] == '\t' || arg[i] == '\v')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

/*
MIN_INT −2,147,483,648 (11 symbols)
MAX_INT 2,147,483,647 (10 symbols)
*/
static int	check_num_is_int(char *arg)
{
	int	i;
	int	len;
	int	number;

	i = 0;
	len = ft_strlen(arg);
	while (arg[i] == ' ' || arg[i] == '\f' || arg[i] == '\n'
		|| arg[i] == '\r' || arg[i] == '\t' || arg[i] == '\v')
		i++;
	if (len - i > 11)
		return (-1);
	number = ft_atoi(arg);
	if (arg[i] == '-' && number > 0)
		return (-1);
	else if (number < 0 && arg[i] != '-')
		return (-1);
	return (0);
}

static int	num_is_in_list(int number, t_list *list_a)
{
	while (list_a != NULL)
	{
		if (list_a->data == number)
			return (-1);
		list_a = list_a->next;
	}
	return (0);
}

/*
arg - for iterating through argv (argv[arg])
i - for iterating through argv[arg] (argv[arg][i])
*/
/*
If no parameters are specified, 
the program must not display anything and give the prompt back.
In case of error, display Error followed by a ’\n’ on the standard error.
Errors include for example: 
- some arguments aren’t integers, 
- some arguments are bigger than an integer, 
- and/or there are duplicates.
*/
int	check_arguments(int argc, char **argv, t_list **list_a)
{
	int	arg;
	int	number;

	arg = 1;
	while (arg < argc)
	{
		if (check_num(argv[arg]) == -1 || check_num_is_int(argv[arg]) == -1)
		{
			ft_lstdelete(list_a);
			print_error();
		}
		number = ft_atoi(argv[arg]);
		if (num_is_in_list(number, *list_a) == -1)
		{
			ft_lstdelete(list_a);
			print_error();
		}
		ft_lstadd_back(list_a, ft_lstnew(number));
		arg++;
	}
	return (0);
}
