/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:53 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:03:56 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	slow_down_even(t_philo *philo)
{
	if (philo->index % 2 == 0)//philosopherのindexが偶数の場合
		usleep(1000);
	//usleepすることで奇数番目のphilosopherが先にforksを取れる
}

void	start_philosophers(t_philo *philo)
{
	taking_fork(philo);
	eating(philo);
	sleeping(philo);
	thinking(philo);
}

void	monitoring(t_philo *philo)
{
	pthread_t	monitor_thread;

	pthread_create(&monitor_thread, NULL, monitor, philo);
	pthread_detach(monitor_thread);
}

/*
 * pthread_create関数の第３引数は戻り値と引数それぞれが
 * void *である必要がある.第3引数は新しいスレッドで実行する関数。
 * ↓
 */

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	philo->last_eat_time = get_time();
	monitoring(philo);
	slow_down_even(philo);//デッドロック回避
	while (1)
	{
		pthread_mutex_lock(&philo->info->shared_mutex);
		if (philo->info->is_alive == false)
			break ;
		pthread_mutex_unlock(&philo->info->shared_mutex);
		start_philosophers(philo);
	}
	pthread_mutex_unlock(&philo->info->shared_mutex);
	return (NULL);

