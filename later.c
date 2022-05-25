#include "./includes/minishell.h"

void	signal_handler(int signal)
{
	char c;
	struct termios	term;

	//signal(signal, SIG_IGN);
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		/*세 줄에 대해서 다시 조사해보기
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		*/
		/*tcgetattr(STDIN_FILENO, &term);
		term.c_lflag &= ~ICANON;
		term.c_lflag &= ~ECHO;
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);*/
		return ;
	}
}

void	execute(char **command, char **envp)
{
	char	*path;

	path = find_path(command[0], envp);
	if (execve(path, command, envp) == -1)
	{
		printf("execve fail\n");
		exit(EXIT_FAILURE);
	}
}

void	running_execute(char **command, t_info *info)//단순 실행
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execute(command, info->envp);
	}
	waitpid(pid, NULL, 0);
}