#include "philosophers.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
	c == '\r' || c == ' ');
}

long long	ft_atoll(char *str)
{
	long long	ret;
	int			flag;

	ret = 0;
	flag = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		flag = -1;
		if (*(++str) == '0')
		{
			printf("-0 is not number\n");
			return (-1);
		}
	}
	while (*str && '0' <= *str && *str <= '9')
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (ret * flag);
}
