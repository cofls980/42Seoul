#include "libft.h"

int		ft_numlen(int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*str;

	len = ft_numlen(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		tmp = n % 10;
		str[--len] = '0' + (tmp < 0 ? -tmp : tmp);
		n /= 10;
	}
	return (str);
}
