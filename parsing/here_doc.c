#include "../includes/minishell.h"

int	func(char *limit, char *input, int fd)
{
	if (ft_strcmp(limit, input) == 0)
	{
		free(input);
		return (0);
	}
	if (input[0] != '\0')
	{
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
	}
	free(input);
	return (1);
}

int	here_doc(char *limit) //ctrl^C누를 떄 끝나야하는뎅.... ctrl^D 누르면 끝나넹...?
{
	char	*input;
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
		return (-1);
	/*while (1)
	{
		input = readline("> ");
		if (!input) //고민
		{
			//printf("minishell: warning: here-document at line 299 delimited by end-of-file\n");//error_mssg
			break ;
		}
		else
		{
			if (!func(limit, input, fd[1]))
				break ;
		}
	}*/
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			signal(SIGINT, ft_here_doc_sig);
			input = readline("> ");
			if (!input) //고민
				break ;
			else
			{
				if (!func(limit, input, fd[1]))
					break ;
			}
		}
		exit(0);
	}
	signal(SIGINT, ft_here_doc_sig);
	close(fd[1]);
	waitpid(pid, &status, 0);
	g_exit_num = (status & 0xff00) >> 8;
	printf("g_exit_num: %d\n", g_exit_num);
	return (fd[0]);
}