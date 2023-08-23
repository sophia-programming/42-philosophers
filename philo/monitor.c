#include "philosophers.h"

void	*monitor(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	while (1)
	{
		pthread_mutex_lock(&philo->info->shared_mutex);
		if (philo->info->is_alive == false)
			break ;
		//最後の食事からの経過時間が死亡時間を超えているかチェック
		if (get_time() - philo->last_eat_time >= philo->info->die_time)
		{
			print_action(DIE, philo);
			break ;
		}
		pthread_mutex_unlock(&philo->info->shared_mutex);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->info->shared_mutex);
	return (NULL);
}
