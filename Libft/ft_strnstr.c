#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (big[i + j] && little[j])
			{
				if (big[i + j] != little[j] || i + j >= len)
					break ;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
