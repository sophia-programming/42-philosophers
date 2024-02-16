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

#include "../header/philosophers.h"

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
	}
	pthread_mutex_unlock(&philo->info->shared_mutex);
}

void	print_philo_action(size_t print_time, size_t philo_index,
			const char *color, const char *action)
{
	printf("%s", color);
	printf("%zu %zu %s\n", print_time, philo_index, action);
	printf("%s", get_color(STOP));
}

void	print_action(t_action action, t_philo *philo)
{
	size_t	print_time;

	pthread_mutex_lock(&philo->info->print_mutex);
	print_time = get_time() - philo->info->start_time;
	if (philo->info->is_alive)
	{
		if (action == TAKING_FORK)
			print_philo_action(print_time, philo->index,
				get_color(GREEN), "has taken a fork");
		else if (action == EATING)
		{
			print_philo_action(print_time, philo->index,
				get_color(CYAN), "is eating");
			everyone_eat_count_check(philo);
		}
		else if (action == SLEEPING)
			print_philo_action(print_time, philo->index,
				get_color(BOLD), "is sleeping");
		else if (action == THINKING)
			print_philo_action(print_time, philo->index,
				get_color(BLUE), "is thinking");
		else if (action == DIE)
		{
			print_philo_action(print_time, philo->index,
				get_color(RED), "died");
			philo->info->is_alive = false;
		}
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
}
