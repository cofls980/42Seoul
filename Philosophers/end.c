#include "./includes/philo.h"

void	the_end(t_data *data)
{
	int	i;

	i = 0;
	while (++i <= data->philos_num)
		pthread_join(data->tid[i], NULL);
	while (++i <= data->philos_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mutex);
	}
	pthread_mutex_destroy(&data->print_mutex);
	free(data->forks);
	free(data->forks_used);
	free(data->philos);
	free(data->tid);
}
