/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:04:14 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:04:14 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
	c == '\r' || c == ' ');
}

int64_t	ft_atoll(char *str)
{
	int64_t		ret;
	int			flag;
	int			i;

	ret = 0;
	flag = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		flag = -1;
		if (str[i] == '0')
		{
			printf("-0 is not number\n");
			return (-1);
		}
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * flag);
}
