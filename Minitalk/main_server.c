/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:06:04 by coverand          #+#    #+#             */
/*   Updated: 2022/01/12 15:27:33 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

/*Allocates and returns a new string, 
which is the result of the concatenation of ’s1’ and ’s2’*/
char	*ft_strjoin_mod(char const *s1, char ch)
{
	int		len1;
	char	*str;
	int		i;

	if (!s1)
		return (0);
	i = 0;
	len1 = ft_strlen(s1);
	str = malloc(sizeof(*str) * (len1 + 1) + 1);
	if (str == 0)
		return (0);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = ch;
	i++;
	str[i] = '\0';
	return (str);
}

/*The function copies string. Memory is allocated using malloc.*/
/*Return val - NULL if memory wasn't allocated.**
** Otherwise - pointer to duplicated string.*/
char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	i = ft_strlen(str);
	dest = (char *)malloc(sizeof(*dest) * i + 1);
	if (dest == 0)
		return (0);
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static void	ft_receive_message(int sig, siginfo_t *info, void *ucontext)
{
	static char	out_char = 0;
	static int	bits = 0;
	static char	*str_to_print;

	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
		out_char = out_char + (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		if (!str_to_print)
			str_to_print = ft_strdup("");
		if (out_char != '\0')
			str_to_print = ft_strjoin_mod(str_to_print, out_char);
		if (out_char == '\0')
		{
			write(1, str_to_print, ft_strlen(str_to_print));
			free(str_to_print);
			str_to_print = NULL;
		}
		out_char = 0;
		bits = 0;
	}
}

/*
1) Initialize sigaction struct.
2) Print process's PID.
3) ft_receive_message - message handler. 
It's address passed via sa.sa_sigaction.
4) SA_SIGINFO tells that ft_receive_message receives 3 params:
- sig - signal number;
- info - pointer to struct that contains info about signal;
- uncontext  - rarely used in handler msg function.

See: https://man7.org/linux/man-pages/man2/sigaction.2.html
pause() causes the calling process to sleep until a signal is delivered.
*/
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_putstr(FRED"Oooops, it seems that you entered too many args.\n"NONE);
		ft_putstr(FRED"Usage: ./server\n"NONE);
		(void)argv;
		exit(EXIT_FAILURE);
	}
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putstr(FCYAN"\nWaiting for message...\n"NONE);
	sa.sa_sigaction = &ft_receive_message;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
