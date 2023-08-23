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
