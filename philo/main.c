#include "philosophers.h"

int	print_usage(void)
{
	printf(RED"[usage]\n" \
			  " [1]:number_of_philosophers\n" \
			  " [2]:time_to_die\n" \
			  " [3]:time_to_eat_time\n" \
			  " [4]:time_to_sleep\n" \
			  "([5]:number_of_each_philosophers_must_eat)\n"STOP);
	return (FAILURE);
}

void	mutex_destroy(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nb_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->shared_mutex);
	pthread_mutex_destroy(&info->print_mutex);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!(argc == 5 || argc == 6))
		return (print_usage());
	if (init_info(&info, argc, argv) == FAILURE)
		return (FAILURE);
	if (info.nb_philo == 1)
		return (only_one_philosopher(&info));
	launch_threads(&info);
	mutex_destroy(&info);
}
