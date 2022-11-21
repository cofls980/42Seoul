#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	if (!dst && !src)
		return (0);
	i = 0;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (dst < src)
		while (len--)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	else
	{
		i = len - 1;
		while (len--)
		{
			dst_tmp[i] = src_tmp[i];
			i--;
		}
	}
	return (dst);
}
