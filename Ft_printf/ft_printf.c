#include "ft_printf.h"

void	ft_find(char c, char flag, va_list ap, int *cnt)
{
	unsigned int	hex;

	if (c == 'c')
		ft_putchar(va_arg(ap, int), cnt);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), cnt);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), flag, cnt);
	else if (c == 'u')
		ft_putunnbr(va_arg(ap, unsigned int), cnt);
	else if (c == 'x' || c == 'X')
	{
		hex = va_arg(ap, unsigned int);
		if (flag == '#' && hex != 0)
		{
			ft_putchar('0', cnt);
			ft_putchar(c, cnt);
		}
		ft_puthex(hex, c, cnt);
	}
	else if (c == 'p')
		ft_putaddr(va_arg(ap, unsigned long long), cnt);
	else if (c == '%')
		ft_putchar('%', cnt);
}

int	ft_afterPercent(const char *fmt, int i, va_list ap, int *cnt)
{
	char	flag;

	if (fmt[i + 1] == '#' || fmt[i + 1] == ' ' || fmt[i + 1] == '+')
	{
		flag = fmt[i + 1];
		if (flag == '#')
			i += 2;
		else
			while (fmt[++i] == flag)
				;
	}
	else
	{
		flag = 'x';
		i++;
	}
	ft_find(fmt[i], flag, ap, cnt);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		cnt;
	va_list	ap;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	i = 0;
	cnt = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			i = ft_afterPercent(fmt, i, ap, &cnt);
		else
			ft_putchar(fmt[i], &cnt);
		i++;
	}
	va_end(ap);
	return (cnt);
}
