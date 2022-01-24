#include "pipex.h"

void	ft_error(char *mssg)
{
	perror(mssg);
	exit(1);
}

void	print(char *str)
{
	int		i;
	char	ch;

	i = 0;
	while (*(str + i))
	{
		ch = *(str + i);
		write(1, &ch, 1);
		i++;
	}
}

char	*find_path_in_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (0);
}

char	*find_path(char *command, char **envp)
{
	char	**en_paths;
	char	*path1;
	char	*path2;
	int	i;

	if (!envp && !command)
		return (0);
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	en_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (en_paths[i])
	{
		path1 = ft_strjoin(en_paths[i], "/");
		path2 = ft_strjoin(path1, command);
		free(path1);
		if (access(path2, F_OK) == 0)
			return (path2);
		i++;
	}
	return (0);
}

void	fork_execve(t_fdlist flist, char *argv, char **envp)
{
	pid_t	pid;
	char	*path;
	char	**comm;

	comm = ft_split(argv, ' ');
	path = find_path(comm[0], envp);
	pid = fork();
	if (pid < 0)
		ft_error("pid error");
	else if (pid == 0)
	{
		close(flist.closefd);
		if (dup2(flist.stdinfd, STDIN_FILENO) == -1)
			ft_error("dup2 error");
		if (dup2(flist.stdoutfd, STDOUT_FILENO) == -1)
			ft_error("dup2 error");
		close(flist.stdinfd);
		close(flist.stdoutfd);
		if (execve(path, comm, envp) == -1)
			ft_error("first execve error");
	}
	if (waitpid(pid, NULL, WNOHANG) == -1)
		ft_error("first waitpid error");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_fdlist flist;
	int		fd_open_file;
	int		fd_output;
	int		fd[2];

	if (argc != 5)
	{
		print("Error: need more parameters\n");
		return (1);
	}
	fd_open_file = open(argv[1], O_RDONLY);
	fd_output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);//0644?
	if (fd_open_file == -1 || fd_output == -1)
		ft_error("file open error");
	if (pipe(fd) == -1)
		ft_error("pipe error");
	flist.closefd = fd[0];
	flist.stdinfd = fd_open_file;
	flist.stdoutfd = fd[1];
	fork_execve(flist, argv[2], envp);
	flist.closefd = fd[1];
	flist.stdinfd = fd[0];
	flist.stdoutfd = fd_output;
	fork_execve(flist, argv[3], envp);
	return (0);
}
