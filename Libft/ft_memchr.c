#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)b;
	while (i < len)
	{
		if (tmp[i] == (unsigned char)c)
			return (tmp + i);
		i++;
	}
	return (0);
}
