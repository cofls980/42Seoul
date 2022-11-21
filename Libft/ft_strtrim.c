#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) && start < end)
		start++;
	i = 0;
	while (i < end)
	{
		if (!ft_strchr(set, s1[end - i - 1]))
			break ;
		i++;
	}
	end = end - i;
	if (start >= end)
		return (ft_strdup(""));
	trim = ft_substr(s1, start, end - start);
	return (trim);
}
