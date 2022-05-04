/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:00:56 by coverand          #+#    #+#             */
/*   Updated: 2022/04/20 18:52:46 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

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

/*Messages*/
# define GET_FORK	"%lu %i has taken a fork\n"
# define EATING		"%lu %i is eating\n"
# define PH_SLEEP	"%lu %i is sleeping\n"
# define PH_THINK	"%lu %i is thinking\n"
# define PHILO_DEAD	"%lu %i died\n"

/*
Struct with input data
*/
typedef struct s_input
{
	int				number;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned long	t_die;
	int				min_eat;
	unsigned long	start_time;
	int				num_overate;
}	t_input;

/*
pthread_t		thread - philo's thread;
int				id - id of i-th philo;
int				meals - number of times philo had meals;
int				min_eat - number of meals that philo should have;
int				finish - 1 if philo should die, 0 otherwise;
unsigned long	last_ate - when was the last time philo ate;
t_input			*input - pointer to struct with all input args;
mutex_t 		*left_fork - left fork mutex;
mutex_t 		*right_fork - right fork mutex;
int				num_left - id of left fork;
int				num_right - id of right fork;
pthread_mutex_t	*max_fork - fork with max id;
pthread_mutex_t	*min_fork - fork with min id;
mutex_t			*msg - mutex 4 printing in stdout;
mutex_t			mutex - when I perform check 
(curr_time - last_ate > input->t_die) I do not update last_ate parametr;
*/
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals;
	int				min_eat;
	int				finish;
	unsigned long	last_ate;
	t_input			*input;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				num_left;
	int				num_right;
	pthread_mutex_t	*max_fork;
	pthread_mutex_t	*min_fork;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*mutex;
}	t_philo;

typedef struct s_data
{
	t_input			input;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	meals_mutex;
	int				num;
}	t_data;

/*File utils.c*/
int				ft_strlen(const char *str);
void			ft_clean(t_data *data);
int				ft_join_threads(t_data *data);
int				ft_print_action(char *msg, unsigned long time, t_philo *philo);

/*File ft_error.c.c*/

int				ft_error(int i);

/*File check_args.c.c*/
int				check_arguments(int argc, char **argv, t_data *data);

/*File ft_init.c.c*/
int				ft_init_forks(t_data *data);
int				ft_init_philos(t_data *data);
int				ft_create_thread(t_data *data);

/*File time.c.c*/
unsigned long	get_time(void);
void			ft_sleep(unsigned long ms);

/*File philo_eat.c.c*/
void			*ft_start(void *philo);

/*File ft_is_dead.c.c*/
int				ft_check_dead(t_data *data);

#endif
