#include "get_next_line.h"

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

int	get_next_line(int fd, char **line)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	int			i;
	int			res;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	while ((res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		backup = ft_strjoin(backup, buf);
		if ((i = is_newline(backup)) != -1)
			return (have_newline(&backup, line, i));
	}
	if (res < 0)
		return (-1);
	return (until_end(&backup, line));
}
