#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest_tmp;
	const unsigned char	*src_tmp;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_tmp = (unsigned char*)dest;
	src_tmp = (const unsigned char*)src;
	while (i < len)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}
