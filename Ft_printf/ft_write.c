#include "ft_printf.h"

void	ft_putchar(char c, int *cnt)
{
	write(1, &c, 1);
	(*cnt)++;
}

void	ft_putstr(const char *str, int *cnt)
{
	size_t	i;

	if (!str)
	{
		ft_putstr("(null)", cnt);
		return ;
	}
	i = 0;
	while (str[i])
		ft_putchar(str[i++], cnt);
}
