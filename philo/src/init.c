/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:21 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:03:23 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

int	init_args(t_info *info, int argc, char **argv)
{
	if (strs_is_digit(argv) == FAILURE || check_arg_size(argv) == FAILURE)
		return (FAILURE);
	if (200 <= ft_atoll(argv[1]))
	{
		error_print("number_of_philosophers should be under 200.");
		return (FAILURE);
	}
	info->nb_philo = ft_atoll(argv[1]);
	info->die_time = ft_atoll(argv[2]);
	info->eat_time = ft_atoll(argv[3]);
	info->sleep_time = ft_atoll(argv[4]);
	if (argc == 6)
	{
		info->must_eat_time = ft_atoll(argv[5]);
		if (ft_atoll(argv[5]) <= 0 || INT_MAX < ft_atoll(argv[5]))
			return (FAILURE);
	}
	else
		info->must_eat_time = UNUSED;
	return (SUCCESS);
}

void	init_philo(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philo[i].index = i + 1;
		info->philo[i].info = info;
		info->philo[i].right_hand = info->philo[i].index - 1;
		if (info->philo[i].index != info->nb_philo)
			info->philo[i].left_hand = info->philo[i].index;
		else
			info->philo[i].left_hand = 0;
		info->philo[i].eat_count = 0;
		info->philo[i].last_eat_time = 0;
		i++;
	}
	info->total_eat_time = 0;
	info->is_alive = true;
}

void	init_mutex(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->shared_mutex, NULL);
	pthread_mutex_init(&info->print_mutex, NULL);
}

int	init_info(t_info *info, int argc, char **argv)
{
	if (init_args(info, argc, argv) == FAILURE)
		return (FAILURE);
	init_philo(info);
	init_mutex(info);
	return (SUCCESS);
}
