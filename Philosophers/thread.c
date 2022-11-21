#include "./includes/philo.h"

int	tid_malloc(t_data *data)
{
	data->tid = (pthread_t *)malloc(sizeof(pthread_t) * (data->philos_num + 1));
	if (!data->tid)
	{
		free(data->forks);
		free(data->philos);
		free(data->forks_used);
		return (0);
	}
	return (1);
}

void	philo_thread(t_data *data)
{
	int	i;

	i = 1;
	data->start = get_time();
	while (i <= data->philos_num)
	{
		pthread_create(&data->tid[i], NULL,
			routine, (void *)&(data->philos[i]));
		i++;
	}
}
