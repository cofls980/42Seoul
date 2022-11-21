#include "./includes/philo.h"

void	hold_forks_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	philo->data->forks_used[philo->left] = 1;
	ft_print(philo, FORK);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	philo->data->forks_used[philo->right] = 1;
	ft_print(philo, FORK);
}

void	hold_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	philo->data->forks_used[philo->right] = 1;
	ft_print(philo, FORK);
	if (philo->data->philos_num == 1)
	{
		ft_usleep(philo->data->time_to_die);
		philo->data->forks_used[philo->right] = 0;
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->forks[philo->right]);
		return ;
	}
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	philo->data->forks_used[philo->left] = 1;
	ft_print(philo, FORK);
}

void	eat_food(t_philo *philo)
{
	if (ft_print(philo, EAT) == 0)
		return ;
	pthread_mutex_lock(&philo->mutex);
	philo->used = 1;
	philo->getting_die = get_time();
	if (philo->data->optional_time != -1)
		philo->eat_count++;
	philo->used = 0;
	pthread_mutex_unlock(&philo->mutex);
	ft_usleep(philo->data->time_to_eat);
}

void	put_forks_down(t_philo *philo)
{
	ft_print(philo, SLEEP);
	if (philo->num % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->right]);
		philo->data->forks_used[philo->right] = 0;
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		philo->data->forks_used[philo->left] = 0;
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		philo->data->forks_used[philo->left] = 0;
		pthread_mutex_unlock(&philo->data->forks[philo->right]);
		philo->data->forks_used[philo->right] = 0;
	}
}

void	sleep_and_think(t_philo *philo)
{
	if (philo->data->dead)
		return ;
	ft_usleep(philo->data->time_to_sleep);
	if (ft_print(philo, THINK) == 0)
		return ;
	usleep(50);
}
