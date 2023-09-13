/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:47 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:03:51 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//各哲学者の食事回数と全体の食事回数を監視し、必要な回数食事をおえたかどうか判断する関数
void	everyone_eat_count_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->shared_mutex);
	philo->last_eat_time = get_time();
	philo->eat_count++;
	if (philo->eat_count == philo->info->must_eat_time)
	{
		philo->info->total_eat_time++;
		if (philo->info->total_eat_time == philo->info->nb_philo)
			philo->info->is_alive = false;
		//全員が必要な回数食事を終えたのでプログラム停止
	}
	pthread_mutex_unlock(&philo->info->shared_mutex);
}

//lockを取得したスレッドだけがprint操作を行えるように制御。
//mutexは一度に一つのスレッドしかロックできない性質を持っている
void	print_action(t_action action, t_philo *philo)
{
	size_t	print_time;

	pthread_mutex_lock(&philo->info->print_mutex);
	print_time = get_time() - philo->info->start_time;
	if (philo->info->is_alive == true)
	{
		if (action == TAKING_FORK)
			printf(GREEN"%zu %zu has taken a fork\n"STOP, print_time, \
		philo->index);
		else if (action == EATING)
		{
			printf(CYAN"%zu %zu is eating\n"STOP, print_time, philo->index);
			everyone_eat_count_check(philo);
		}
		else if (action == SLEEPING)
			printf(BOLD"%zu %zu is sleeping\n"STOP, print_time, philo->index);
		else if (action == THINKING)
			printf(BLUE"%zu %zu is thinking\n"STOP, print_time, philo->index);
		else if (action == DIE)
		{
			printf(RED"%zu %zu died\n"STOP, print_time, philo->index);
			philo->info->is_alive = false;
		}
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
}