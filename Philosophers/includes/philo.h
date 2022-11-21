#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

struct	s_data;

typedef struct s_philo
{
	int				num;
	int				left;
	int				right;
	long long		eat_count;
	int				used;
	long long		getting_die;
	pthread_mutex_t	mutex;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philos_num;
	long long		start;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		optional_time;
	int				dead;
	int				*forks_used;
	pthread_t		*tid;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}	t_data;

long long	ft_atoi(char *str);
void		*all_monitoring(void *arg);
int			ft_print(t_philo *philo, int flag);
long long	get_time(void);
void		ft_usleep(long long ms);
int			change_to_number(t_data *data, int argc, char **argv);
int			ft_malloc(t_data *data);
void		init(t_data *data);
void		*routine(void *arg);
void		philo_thread(t_data *data);
void		the_end(t_data *data);
void		hold_forks(t_philo *philo);
void		eat_food(t_philo *philo);
void		put_forks_down(t_philo *philo);
void		sleep_and_think(t_philo *philo);
int			is_number_check(char *number);
int			error_check(t_data *data, int argc, char **argv);
void		hold_forks_even(t_philo *philo);
int			tid_malloc(t_data *data);

#endif
