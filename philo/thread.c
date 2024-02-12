/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:04:00 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:04:02 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

void	launch_threads(t_info *info)
{
	size_t	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->nb_philo)
	{
		pthread_create(&info->philo[i].thread, NULL, \
		philo_routine, &info->philo[i]);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
}
