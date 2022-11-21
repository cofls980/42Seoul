#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int value, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)value)
			break ;
		i++;
	}
	return (i == len ? 0 : dest + i + 1);
}
