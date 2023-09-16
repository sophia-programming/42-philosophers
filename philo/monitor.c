/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:33 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:03:35 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	while (true)
	{
		pthread_mutex_lock(&philo->info->shared_mutex);
		if (philo->info->is_alive == false)
			break ;
		if (philo->info->die_time <= get_time() - philo->last_eat_time)
		{
			print_action(DIE, philo);
			break ;
		}
		pthread_mutex_unlock(&philo->info->shared_mutex);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->info->shared_mutex);
	return (NULL);
}
