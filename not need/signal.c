#include "./includes/minishell.h"

void	signal_handler(int signal)
{
	//char c;
	//struct termios	term;

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
