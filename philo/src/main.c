/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:59:00 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/16 16:59:02 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

int	print_usage(void)
{
	error_print("[usage]\n" \
				" [1]:number_of_philosophers\n" \
				" [2]:time_to_die\n" \
				" [3]:time_to_eat\n" \
				" [4]:time_to_sleep\n" \
				"([5]:number_of_times_each_philosopher_must_eat)");
	return (FAILURE);
}

void	mutex_destroy(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->shared_mutex);
	pthread_mutex_destroy(&info->print_mutex);
}

int	parse_args(int argc, char **argv, t_params *params)
{
	if (argc < 5 || argc > 6)
		return (FAILURE);
	params->num_philosophers = ft_atoll(argv[1]);
	params->time_to_die = ft_atoll(argv[2]);
	params->time_to_eat = ft_atoll(argv[3]);
	params->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		params->num_of_times_each_philosopher_must_eat = ft_atoll(argv[5]);
	else
		params->num_of_times_each_philosopher_must_eat = UNUSED;
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info		info;
	t_params	params;

	if (parse_args(argc, argv, &params) == FAILURE)
		return (print_usage());
	info.nb_philo = params.num_philosophers;
	info.die_time = params.time_to_die;
	info.eat_time = params.time_to_eat;
	info.sleep_time = params.time_to_sleep;
	info.must_eat_time = params.num_of_times_each_philosopher_must_eat;
	if (init_info(&info, argc, argv) == FAILURE)
		return (FAILURE);
	if (info.nb_philo == 1)
		return (only_one_philosopher(&info));
	launch_threads(&info);
	mutex_destroy(&info);
}
