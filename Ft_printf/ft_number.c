#include "ft_printf.h"

void	ft_putdec(int n, int *cnt)
{
	if (n <= -10 || n >= 10)
		ft_putdec(n / 10, cnt);
	n %= 10;
	if (n < 0)
		ft_putchar('0' + -n, cnt);
	else
		ft_putchar('0' + n, cnt);
}

void	ft_putnbr(int n, char flag, int *cnt)
{
	if (n < 0)
		ft_putchar('-', cnt);
	else if (flag == ' ' || flag == '+')
		ft_putchar(flag, cnt);
	ft_putdec(n, cnt);
}

void	ft_putunnbr(unsigned int n, int *cnt)
{
	if (n >= 10)
		ft_putunnbr(n / 10, cnt);
	n %= 10;
	ft_putchar('0' + n, cnt);
}

void	ft_puthex(unsigned int n, char c, int *cnt)
{
	if (n >= 16)
		ft_puthex(n / 16, c, cnt);
	n %= 16;
	if (n <= 9)
		ft_putchar('0' + n, cnt);
	else if (c == 'x')
		ft_putchar('0' + n + 39, cnt);
	else if (c == 'X')
		ft_putchar('0' + n + 7, cnt);
}
