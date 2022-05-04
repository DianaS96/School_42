/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:31:37 by coverand          #+#    #+#             */
/*   Updated: 2022/01/11 14:02:35 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*stdlib.h - for exit function*/
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/*fonts color*/
# define FBLACK		"\033[0;30m"
# define FRED		"\033[0;31m"
# define FGREEN		"\033[0;32m"
# define FYELLOW	"\033[0;33m"
# define FBLUE		 "\033[0;34m"
# define FPURPLE	"\033[0;35m"
# define FCYAN		"\x1b[36m"

/*end color*/
# define NONE        "\033[0m"

int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_check_pid(char *pid);

#endif
