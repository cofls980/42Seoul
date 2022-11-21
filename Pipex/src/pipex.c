#include "../includes/pipex.h"

void	execute(t_info info, int index)
{
	char	*path;
	char	**command;

	command = ft_split(info.argv[index], ' ');
	if (command == NULL)
		display_error("find command error"); //넣을까말까
	path = find_path(command[0], info.envp);
	if (path == NULL)
		display_error("find command path error"); //넣을까말까
	if (execve(path, command, info.envp) == -1)
	{
		free(path);
		free_str(command);
		display_error("command not found\n");
	}
}

int	command_outfile(t_info info, int outfilefd, int index)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		display_error("fork error");
	else if (pid == 0)
	{
		duplicate(outfilefd, STDOUT_FILENO);
		execute(info, index);
	}
	return (pid);
}

pid_t command(t_info info, int index)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		display_error("pipe error");
	pid = fork();
	if (pid < 0)
		display_error("fork error");
	else if (pid == 0)
	{
		close_fd(fd[0]);
		duplicate(fd[1], STDOUT_FILENO);
		execute(info, index);
	}
	close_fd(fd[1]);
	duplicate(fd[0], STDIN_FILENO);
	return (pid);
}

void    pipex(t_info info, int outfilefd, int size, int start)
{
    int     i;
	int		index;
    pid_t	*pids;

    pids = (pid_t *)malloc(sizeof(pid_t) * size);
    i = 0;
    while (i + start < info.argc - 2)
	{
		index = start + i++;
		pids[i] = command(info, index);
	}
    i = 0;
    while(i < size)
        waitpid(pids[i++], NULL, 0);
    free(pids);
}