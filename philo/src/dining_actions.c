/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:22:08 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/11 00:59:16 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->right_hand]);
	print_action(TAKING_FORK, philo);
	pthread_mutex_lock(&philo->info->forks[philo->left_hand]);
	print_action(TAKING_FORK, philo);
}

void	eating(t_philo *philo)
{
	print_action(EATING, philo);
	precise_sleep(philo->info->eat_time);
	pthread_mutex_unlock(&philo->info->forks[philo->right_hand]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_hand]);
}

void	sleeping(t_philo *philo)
{
	print_action(SLEEPING, philo);
	precise_sleep(philo->info->sleep_time);
}

void	thinking(t_philo *philo)
{
	print_action(THINKING, philo);
}
