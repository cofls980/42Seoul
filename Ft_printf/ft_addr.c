#include "ft_printf.h"

void	ft_addrhex(unsigned long long addr, int *cnt)
{
	if (addr >= 16)
		ft_addrhex(addr / 16, cnt);
	addr %= 16;
	if (addr <= 9)
		ft_putchar('0' + addr, cnt);
	else
		ft_putchar('0' + addr + 39, cnt);
}

void	ft_putaddr(unsigned long long str, int *cnt)
{
	ft_putstr("0x", cnt);
	ft_addrhex((unsigned long long)str, cnt);
}
