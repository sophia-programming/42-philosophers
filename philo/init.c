#include "philosophers.h"

int	init_args(t_info *info, int argc, char **argv)
{
	if (strs_is_digit(argv) == FAILURE || check_arg_size(argv) == FAILURE)
		return (FAILURE);
	if (ft_atoll(argv[1]) >= 200)
	{
		printf(RED"number_of_philosophers should be under 200.\n"STOP);
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

/*
 * {0} 初期化が有効なケースは、特にデフォルトの初期値やゼロクリアが
 * 必要な場面で使われることが多いですが、各メンバーに個別の初期値や計算を適用する場合には、
 * 個々の初期化コードを記述する必要があります。
 *
 * ということで下記のコードでこの{0}を使って初期化はできなさそうだ。
 *
 */
void	init_philo(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philo[i].index = i + 1; //通常通り数えた時と同じindexにするため
		info->philo[i].info = info;
		info->philo[i].right_hand = info->philo[i].index - 1;//philosopherのindexに合わせるため
		if (info->philo[i].index != info->nb_philo)
			info->philo[i].left_hand = info->philo[i].index;//左隣にいるフィロソファーの番号を示すためであり、そのままの値を使用する方が適切
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
		pthread_mutex_init(&info->forks[i++], NULL);
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
