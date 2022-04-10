#include "../includes/pipex.h"

int open_file(char *file, int num)
{
	int fd;

	if (num == 0)
		fd = open(file, O_RDONLY);
	else if (num == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (num == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		display_error("open file descriptor error\n");
	return (fd);
}

void	display_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

void	close_fd(int fd)
{
	if (close(fd) == -1)
		display_error("close file descriptor error\n");
}

void	duplicate(int fd, int dup_fd)
{
	if (dup2(fd, dup_fd) == -1)
		display_error("dup2 error\n");
	close_fd(fd);
}