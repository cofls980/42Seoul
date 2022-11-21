#include "./includes/philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->getting_die = get_time();
	if (philo->num % 2 == 0)
		usleep(10);
	while (!philo->data->dead)
	{
		if (philo->num % 2 == 0)
			hold_forks_even(philo);
		else
			hold_forks(philo);
		eat_food(philo);
		if (philo->data->philos_num != 1)
			put_forks_down(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	tid;

	if (!error_check(&data, argc, argv))
		return (0);
	init(&data);
	philo_thread(&data);
	usleep(400);
	pthread_create(&tid, NULL, all_monitoring, &data);
	pthread_join(tid, NULL);
	the_end(&data);
	return (0);
}
