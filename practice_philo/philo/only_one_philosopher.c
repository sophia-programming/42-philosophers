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

#include "philosophers.h"

int	only_one_philosopher(t_info *info)
{
	info->start_time = get_time();//ここの段階では0マイクロ秒
	printf(GREEN"0 %zu has taken a fork\n"STOP, info->philo->index);
	precise_sleep(info->die_time);
	printf(RED"%zu %zu died\n"STOP, \
	get_time() - info->start_time, info->philo->index);
		   /*
		    * get_time() - info->start_time でphilosopherが死んだときの
		    * 経過時間を示す。
		    * info->philo->index でphilosopherのindexを表す
		    */
	return (SUCCESS);
}
