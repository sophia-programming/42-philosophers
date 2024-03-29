/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:09 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:03:13 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include "macro.h"

typedef enum e_action
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIE,
}	t_action;

typedef enum e_color
{
	STOP,
	BOLD,
	RED,
	GREEN,
	BLUE,
	CYAN,
}	t_color;

typedef struct s_info	t_info;

typedef struct s_philo
{
	ssize_t		eat_count;
	t_info		*info;
	size_t		index;
	size_t		left_hand;
	size_t		right_hand;
	size_t		last_eat_time;
	pthread_t	thread;
}	t_philo;

typedef struct s_info
{
	size_t			nb_philo;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	ssize_t			must_eat_time;
	size_t			start_time;
	size_t			total_eat_time;
	pthread_mutex_t	forks[MAX_NB_PHILO];
	pthread_mutex_t	shared_mutex;
	pthread_mutex_t	print_mutex;
	bool			is_alive;
	t_philo			philo[MAX_NB_PHILO];
}	t_info;

typedef struct s_params {
	int	num_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philosopher_must_eat;
}	t_params;

int			init_info(t_info *info, int argc, char **argv);
void		debug_info(t_info *info);
void		launch_threads(t_info *info);
size_t		get_time(void);
void		*philo_routine(void *philopher);
void		taking_fork(t_philo *philo);
void		print_action(t_action action, t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		precise_sleep(size_t time);
void		thinking(t_philo *philo);
void		*monitor(void *philosopher);
int			only_one_philosopher(t_info *info);
int64_t		ft_atoll(char *str);
int			check_arg_size(char **argv);
int			strs_is_digit(char **strs);
void		error_print(char *str);
const char	*get_color(t_color color);
void		print_philo_action(size_t print_time, size_t philo_index,
				const char *color, const char *action);
#endif
