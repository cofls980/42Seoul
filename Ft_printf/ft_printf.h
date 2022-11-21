#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c, int *cnt);
void	ft_putstr(const char *str, int *cnt);
void	ft_putdec(int n, int *cnt);
void	ft_putnbr(int n, char flag, int *cnt);
void	ft_putunnbr(unsigned int n, int *cnt);
void	ft_puthex(unsigned int n, char c, int *cnt);
void	ft_addrhex(unsigned long long addr, int *cnt);
void	ft_putaddr(unsigned long long str, int *cnt);
void	ft_find(char c, char flag, va_list ap, int *cnt);

#endif
