#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dst;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *dst, const char *src)
{
	char	*str;
	int		dst_len;
	int		src_len;
	int		i;

	if (!dst && !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!(str = (char *)malloc(sizeof(char) * (dst_len + src_len + 1))))
		return (0);
	i = dst_len;
	while (i--)
		str[i] = dst[i];
	free(dst);
	str[dst_len + src_len] = '\0';
	while (src_len--)
		str[dst_len + src_len] = src[src_len];
	return (str);
}
