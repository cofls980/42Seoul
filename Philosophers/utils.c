#include "./includes/philo.h"

long long	ft_atoi(char *str)
{
	long long	res;
	long long	i;

	res = 0;
	i = -1;
	while (str[++i])
	{
		res *= 10;
		res += (str[i] - '0');
	}
	return (res);
}

long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_usleep(long long ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < (long long)ms)
		usleep(350);
}

int	is_number_check(char *number)
{
	int	i;
	int	zero;

	zero = 0;
	while (number[zero] && number[zero] == '0')
		zero++;
	i = zero;
	while (number[i])
	{
		if (!('0' <= number[i] && number[i] <= '9'))
			return (0);
		i++;
	}
	if (zero == i)
		return (0);
	return (1);
}
