#include "../includes/pipex.h"

void	free_str(char **en_paths)
{
	int	i;

	i = 0;
	if (en_paths)
	{
		while (en_paths[i])
		{			
			free(en_paths[i]);
			i++;
		}
		free(en_paths);
	}
}

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
	str = (char *)malloc(sizeof(char) * (one + two + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < one)
	{
		str[i] = s1[i];
	}
	i = -1;
	while (++i < two)
	{
		str[one + i] = s2[i];
	}
	str[one + two] = '\0';
	return (str);
}

int ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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