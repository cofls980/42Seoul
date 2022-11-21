#include "libft.h"

void	*ft_memset(void *dest, int value, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char*)dest;
	while (i < len)
	{
		tmp[i] = (unsigned char)value;
		i++;
	}
	return (tmp);
}
