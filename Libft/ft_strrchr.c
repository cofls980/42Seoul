#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		last = (char *)s + i;
	return (last);
}
