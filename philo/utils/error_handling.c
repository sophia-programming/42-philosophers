/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:18 by oaoba             #+#    #+#             */
/*   Updated: 2023/09/12 14:03:19 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

int	str_is_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	strs_is_digit(char **strs)
{
	size_t	i;

	i = 1;
	while (strs[i])
	{
		if (str_is_digit(strs[i]) == FAILURE)
		{
			error_print("argv includes invalid character!");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_arg_size(char **argv)
{
	if (ft_atoll(argv[1]) <= 0 || INT_MAX < ft_atoll(argv[1]) \
	|| ft_atoll(argv[2]) <= 0 || INT_MAX < ft_atoll(argv[2]) \
	|| ft_atoll(argv[3]) <= 0 || INT_MAX < ft_atoll(argv[3]) \
	|| ft_atoll(argv[4]) <= 0 || INT_MAX < ft_atoll(argv[4]))
	{
		error_print("0 < argv[1] && argv[1] <= INT_MAX\n" \
		"0 < argv[2] && argv[2] <= INT_MAX\n" \
		"0 < argv[3] && argv[3] <= INT_MAX\n" \
		"0 < argv[4] && argv[4] <= INT_MAX\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

void	error_print(char *str)
{
	printf(RED"%s\n"STOP, str);
}
