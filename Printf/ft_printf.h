/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:18:33 by coverand          #+#    #+#             */
/*   Updated: 2021/12/03 19:26:37 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
types:
• %c print a single character.
• %s print a string of characters.
• %p The void * pointer argument is printed in hexadecimal.
• %d print a decimal (base 10) number.
• %i print an integer in base 10.
• %u print an unsigned decimal (base 10) number.
• %x print a number in hexadecimal (base 16), with lowercase.
• %X print a number in hexadecimal (base 16), with uppercase.
• %% print a percent sign.
*/

/*From file ft_printf.c*/
int		ft_printf(const char *arg, ...);
int		parse_input(const char *arg, va_list arguments);
/*From file ft_printf_utils.c*/
int		ft_putstr(char *s);
int		ft_putchar(char ch);
int		process_type(char type, va_list arguments);
int		ft_strlen(const char *str);
/*From file check_flags.c*/
int		check_type(char s);
/*From file my_print_c.c*/
int		ft_print_c(char ch);
/*From file my_print_s.c*/
int		ft_print_s(char *str);
/*From file my_print_perc.c*/
int		ft_print_perc(void);
/*From file my_print_id.c*/
int		ft_print_id(int n);
/*From file my_print_u.c*/
int		ft_print_u(unsigned int n);
/*From file my_print_x.c*/
int		ft_print_x(unsigned int n, int capital);
/*From file my_print_p.c*/
int		ft_print_p(unsigned long long n);
/*From file ft_utoa.c*/
char	*ft_utoa(unsigned int n);
/*From file ft_itoa_x.c*/
char	*ft_itoa_x(unsigned long n, int capital);
/*From file ft_itoa.c*/
char	*ft_itoa(int n);

#endif
