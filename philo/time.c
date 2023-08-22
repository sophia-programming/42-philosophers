#include "philosophers.h"

size_t	get_time(void)
{
	struct timeval	tp;
	size_t			ms;

	gettimeofday(&tp, NULL);//第二引数はtzp. 通常はNULL
	ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (ms);
	/*
	 *１秒は*1000してミリ秒に、マイクロ秒は/1000してミリ秒に
	 * 単位変換。
	 */
}

void	precise_sleep(size_t sleep_time)
{
	size_t	end_time;

	end_time = get_time() + sleep_time;
	while (get_time() < end_time)
		usleep(100);
}
