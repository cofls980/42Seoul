#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp[len] = '\0';
	while (len--)
		tmp[len] = str[len];
	return (tmp);
}
