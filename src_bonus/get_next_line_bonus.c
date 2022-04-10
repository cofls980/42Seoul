#include "../includes/pipex_bonus.h"

char	*ft_strjoin_with_free(char *dst, char *src)
{
	char	*str;
	int		dst_len;
	int		src_len;
	int		i;

	if (!dst && !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!str)
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

int	is_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	have_newline(char **backup, char **line, int i)
{
	char	*copy;
	int		len;

	(*backup)[i] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + i + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	copy = ft_strdup(*backup + i + 1);
	free(*backup);
	*backup = copy;
	return (1);
}

int	until_end(char **backup, char **line)
{
	int	i;

	if (*backup)
	{
		if ((i = is_newline(*backup)) != -1)
			return (have_newline(backup, line, i));
		else
		{
			*line = *backup;
			*backup = NULL;
			return (0);
		}
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line, int buf_size)
{
	static char	*backup;
	char		*buf;
	int			i;
	int			res;

	if (!line || buf_size <= 0 || fd < 0)
		return (-1);
	buf = malloc(sizeof(char *) * (buf_size + 1));
	while ((res = read(fd, buf, buf_size)) > 0)
	{
		buf[res] = '\0';
		backup = ft_strjoin_with_free(backup, buf);
		if ((i = is_newline(backup)) != -1)
			return (have_newline(&backup, line, i));
	}
	if (res < 0)
		return (-1);
	return (until_end(&backup, line));
}
