#include "./includes/philo.h"

int	ft_print(t_philo *philo, int flag)
{
	if (philo->data->dead)
	{
		return (0);
	}
	pthread_mutex_lock(&philo->data->print_mutex);
	if (flag == FORK)
		printf("%lld %d %s\n",
			get_time() - philo->data->start, philo->num, "has taken a fork");
	else if (flag == EAT)
		printf("%lld %d %s\n",
			get_time() - philo->data->start, philo->num, "is eating");
	else if (flag == SLEEP)
		printf("%lld %d %s\n",
			get_time() - philo->data->start, philo->num, "is sleeping");
	else if (flag == THINK)
		printf("%lld %d %s\n",
			get_time() - philo->data->start, philo->num, "is thinking");
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (1);
}
