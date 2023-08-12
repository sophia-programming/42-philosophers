#include "philosophers.h"

size_t	get_time(void)
{
	struct timeval	tp;
	size_t			ms;

	gettimeofday(&tp, NULL);
	ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (ms);
}

void	precise_sleep(size_t sleep_time)
{
	size_t	end_time;

	end_time = get_time() + sleep_time;
	while (get_time() < end_time)
		usleep(100);
}
