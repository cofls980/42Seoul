#include "./includes/minishell.h"

void	free_pid(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->have_pipe + 1)
	{
		if (info->pids[i] == -2)
		{
			//printf("%d in\n", i);
			i++;
			continue ;
		}
		waitpid(info->pids[i++], NULL, 0);
		//printf("finished - %d\n", i - 1);
	}
	free(info->pids);
}

void	parsing(char **bundle, t_info *info)
{
	int		i;
	char	**small;

	i = -1;
	while (bundle[++i])
	{
		info->redirect_in = -1;
		info->redirect_out = -1;
		if (!solve_redirect(bundle[i], info))
			break ;
		small = split_words(bundle[i]); // 하나의 단어로 분리
		if (!small)
			break ;//만약에 파이프가 있는 경우이면 continue;가 나을 것 같지 않은가
		if (interpret_quotes(small, info))
			info->error = 5;
		info->pids[i] = command(small, info);
		info->pipe_count--;
		info->redirect = 0;
		free_str(small);
	}
}

void	minishell(char *str, t_info *info)
{
	char	**bundle;

	info->error = 0;
	bundle = split_pipe(str, info); //pipe를 기준으로 문자열 나눔
	if (!bundle)
		return ;
	info->pids = (pid_t *)malloc(sizeof(pid_t) * (info->pipe_count + 1));
	if (!(info->pids))
	{
		printf("minishell: malloc error\n");
		return ;
	}
	info->have_pipe = info->pipe_count;
	parsing(bundle, info);
	dup2(info->output_file, STDOUT_FILENO);
	free_pid(info);
	free_str(bundle);
	info->have_pipe = 0;
	info->pipe_count = 0;
	info->input_file = 0;
	info->output_file = 1;
	info->redirect = 0;
	info->redirect_in = -1;
	info->redirect_out = -1;
	info->here_doc = 0;
	if (info->error == 5)
		error_message(0, 5);
	info->error = -1;
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_info			info;
	struct termios	term;

	if (argc == 1 && ft_strcmp(argv[0], "./minishell"))
	{
		printf("hh\n");
	}
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	tcgetattr(STDIN_FILENO, &term);
	//term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	init(&info, envp);
	g_exit_num = 0;
	while (1)
	{
		input = readline("\033[0;31mminishell> \033[0;37m");
		if (!input)//ctrl^D
		{
			printf("\n");
			break ;
		}
		else if (input[0] == '\0')//minishell>뒤에 아무것도 입력하지않고 엔터만 누른 경우
		{
			free(input);
		}
		else
		{
			add_history(input);
			minishell(input, &info); //입력받은 문자열에 대해 파싱 시작
			free(input);//반드시 free
		}
	}
	//free everything
	return (0);
}