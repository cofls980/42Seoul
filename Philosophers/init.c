#include "./includes/philo.h"

int	change_to_number(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number_check(argv[i]))
			return (0);
		i++;
	}
	data->philos_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->optional_time = ft_atoi(argv[5]);
	else
		data->optional_time = -1;
	return (1);
}

int	ft_malloc(t_data *data)
{
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (data->philos_num + 1));
	if (!data->forks)
		return (0);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * (data->philos_num + 1));
	if (!data->philos)
	{
		free(data->forks);
		return (0);
	}
	data->forks_used = (int *)malloc(sizeof(int) * (data->philos_num + 1));
	if (!data->forks_used)
	{
		free(data->forks);
		free(data->philos);
		return (0);
	}
	if (!tid_malloc(data))
		return (0);
	return (1);
}

void	fork_init(t_data *data, int i)
{
	if (i == 1)
	{
		data->philos[i].left = data->philos_num;
		data->philos[i].right = i;
	}
	else
	{
		data->philos[i].left = i - 1;
		data->philos[i].right = i;
	}
}

void	init(t_data *data)
{
	int	i;

	i = 0;
	while (++i <= data->philos_num)
	{
		data->forks_used[i] = 0;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].mutex, NULL);
		data->philos[i].num = i;
		data->philos[i].used = 0;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		fork_init(data, i);
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	data->dead = 0;
}
