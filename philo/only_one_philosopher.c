#include "philosophers.h"

int	only_one_philosopher(t_info *info)
{
	info->start_time = get_time();
	printf(GREEN"0 %zu has taken a fork\n"STOP, info->philo->index);
	precise_sleep(info->die_time);
	printf(RED"%zu %zu died\n"STOP, \
	get_time() - info->start_time, info->philo->index);
	return (SUCCESS);
}
