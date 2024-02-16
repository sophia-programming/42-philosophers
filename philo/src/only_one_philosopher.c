/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one_philosopher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:36 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:03:39 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

int	only_one_philosopher(t_info *info)
{
	info->start_time = get_time();
	print_philo_action(0, info->philo->index,
		get_color(GREEN), "has taken a fork");
	precise_sleep(info->die_time);
	print_philo_action(info->die_time, info->philo->index,
		get_color(RED), "died");
	return (SUCCESS);
}
