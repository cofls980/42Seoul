#include "../includes/pipex_bonus.h"

void	init_info(int argc, char **argv, char **envp, t_info *info)
{
	info->argv = argv;
	info->envp = envp;
	info->argc = argc;
}

void	ft_putstr(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

void	here_doc(char *limit)
{
	int		fd[2];
	char	*line;
	int		res;
	int		limit_len;

	if (pipe(fd) == -1)
		display_error("pipe error\n");
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
	close_fd(fd[1]);
	duplicate(fd[0], STDIN_FILENO);
	return;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		iofd[2];

	if (argc < 5)
		display_error("need more parameters\n");
	init_info(argc, argv, envp, &info);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		iofd[1] = open_file(argv[argc - 1], 2);
		here_doc(argv[2]);
		pipex(info, iofd[1], 2, 3);
	}
	else
	{
		iofd[0] = open_file(argv[1], 0);
		iofd[1] = open_file(argv[argc - 1], 1);
		duplicate(iofd[0], STDIN_FILENO);
		pipex(info, iofd[1], info.argc - 3, 2);
	}
	return (0);
}