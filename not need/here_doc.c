#include "../includes/minishell.h"

void	ft_putstr(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	here_doc(char *limit, t_info *info)
{
	int		fd[2];
	char	*line;
	int		res;
	int		limit_len;

	if (pipe(fd) == -1) //error mssg
	{
		error_message(0, 4);
		return (-1);
	}
		//display_error("pipe error\n");
	limit_len = ft_strlen(limit);
	while (1)
	{
		ft_putstr(1, "> ");
		res = get_next_line(0, &line, limit_len);
		if (res == -1 || ft_strcmp(line, limit) == 0)
			break;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	free(line);
	close(fd[1]);//close_fd(fd[1]);
	return (fd[0]);
}