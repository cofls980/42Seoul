#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		one;
	int		two;
	int		i;

	if (!s1 && !s2)
		return (0);
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (one + two + 1))))
		return (0);
	i = 0;
	while (i < one)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < two)
	{
		str[one + i] = s2[i];
		i++;
	}
	str[one + two] = '\0';
	return (str);
}
