#include "philosophers.h"

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
			printf(RED"argv includes invalid character!\n"STOP);
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
		printf(RED"0 < argv[1] && argv[1] <= INT_MAX\n" \
		"0 < argv[2] && argv[2] <= INT_MAX\n" \
		"0 < argv[3] && argv[3] <= INT_MAX\n" \
		"0 < argv[4] && argv[4] <= INT_MAX\n" \
		"0 < argv[5] && argv[5] <= INT_MAX\n"STOP);
		return (FAILURE);
	}
	return (SUCCESS);
}
