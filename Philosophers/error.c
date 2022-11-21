#include "./includes/philo.h"

int	error_check(t_data *data, int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
	{
		printf("parameters error\n");
		return (0);
	}
	if (!change_to_number(data, argc, argv))
	{
		printf("parameter is not a NUMBER\n");
		return (0);
	}
	if (!ft_malloc(data))
	{
		printf("malloc error\n");
		return (0);
	}
	return (1);
}
