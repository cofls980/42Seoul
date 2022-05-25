#include "./includes/minishell.h"
/*
	1. pipe를 기준으로 문자열 분리
	2. 1에서 분리된 각 문자열을 따옴표를 고려한 공백을 기준으로 분리
	3. 2번에서 문자열 분리할 때 환경변수도 같이 파싱
	===== 추가 =====
	1. 리다이레션 파싱 추가
	2. $?
	3. 파이프 사용했을 때 처리
		- 입력 문자열 끝이 파이프 기호로 끝난 경우 에러
	', ", | $ < > << >> 제외한 특수문자는 단순 문자로 인식
	4. $뒤에 오는 문자 처리
		- $ 뒤에 바로 숫자가 오면 $[한자리 숫자] 로 해석 ===> http://www.itmoa.co.kr/gzboard.php?code=techqna&mode=gz_read&Page=5&no=222
		- $ 바로 뒤에는 _나 문자가 와야함(숫자는 첫번째만 아니면 된다.)
		- 특수문자를 만나는 동시에 해석 종료 ===> ex) $% 입력이 들어오면 그냥 $% 출력
		- $ 뒤에 아무것도 없으면 그냥 $ 출력
*/
void	parsing(char *str, t_info *info)
{
	int	i;
	int	start;
	char	**bundle;
	char	**small;

	bundle = split_pipe(str); //pipe를 기준으로 문자열 나눔
	if (!bundle)
		return;
	i = 0;
	while (bundle[i])
	{
		small = split_words(bundle[i]); // 하나의 단어로 분리
		interpret_quotes(small, info); // 따옴표와 $기호 해석
		check_command(small, info); // 파싱된 문자열 실행
		free_str(small);
		i++;
	}
	free_str(bundle);
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	char			**command;
	t_info			info;
	struct termios	term;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	init(&info, envp);
	while (1)
	{
		input = readline("\033[0;31mminishell> \033[0;37m");
		if (input)
		{
			add_history(input);
			parsing(input, &info); //입력받은 문자열에 대해 파싱 시작
			free(input);//반드시 free
		}
		else
		{
			printf("\n");
			break ;
		}
	}
	return (0);	
}