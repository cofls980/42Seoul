#include "./includes/philo.h"

int	eat_count_check(t_data *data)
{
	int	i;

	i = 0;
	if (data->optional_time != -1)
	{
		while (++i <= data->philos_num)
		{
			if (data->philos[i].eat_count < data->optional_time)
				return (0);
		}
		data->dead = 1;
		return (1);
	}
	return (0);
}

int	is_dead_check(t_philo *philo)
{
	long long	diff;

	diff = get_time() - philo->getting_die;
	if (diff > philo->data->time_to_die)
	{
		philo->data->dead = 1;
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%lld %d %s\n",
			get_time() - philo->data->start, philo->num, "died");
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (0);
	}
	return (1);
}

void	*all_monitoring(void *arg)
{
	t_data	*data;
	int		i;
	t_philo	*philo;

	data = (t_data *)arg;
	i = 1;
	while (i <= data->philos_num)
	{
		philo = &(data->philos[i++]);
		pthread_mutex_lock(&philo->mutex);
		if (!is_dead_check(philo))
		{
			pthread_mutex_unlock(&philo->mutex);
			break ;
		}
		if (eat_count_check(data))
		{
			pthread_mutex_unlock(&philo->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->mutex);
		if (i == data->philos_num + 1)
			i = 1;
	}
	return (NULL);
}
