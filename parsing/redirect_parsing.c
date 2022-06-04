#include "../includes/minishell.h"

void	insert_space(char *str, int start, int end, t_info *info)
{
	if (info->redirect == 4 || info->redirect == 3)
		start--;
	while (start < end)
	{
		//printf("str: [%c]\n", str[start]);
		str[start] = ' ';
		start++;
	}
}

int	redirection(char *name, t_info *info) // < 1, > 2, << 3, >> 4
{
	int	fd;

	if (info->redirect == 1)
		fd = open(name, O_RDONLY);
	else if (info->redirect == 2) //===>번호를 define사용해서 지정하기
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (info->redirect == 3)//if (here_doc(name, info) == -1) error mssg
		fd = here_doc(name, info);
	else if (info->redirect == 4)
		fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)// open할 때도 없는 파일이면 오픈 못함 error mssg
	{
		error_message(0, 2);//error mssg
		return (0);
	}
	if (info->redirect % 2 == 1)
		info->redirect_in = fd;
	else
		info->redirect_out = fd;
	return (1);
}

int	check_string(char *str, char *name, int len, int start, t_info *info, int redirect_idx, int end)
{
	change_word(name, start, len, str, info); //파일 이름 해석하여 받아오기, start==end
	if (opendir(name) && (info->redirect == 2 || info->redirect == 4))// 이름이 디렉토리이면 오류
	{
		free(name);
		error_message(0, 3);//error mssg
		return (0);
	}
	if (open(name, O_RDONLY) == -1 && info->redirect == 1) //< 없는 파일이면 오류 errno 사용?
	{//echo <includes 테스트해보기
		free(name);
		error_message(0, 2);//error mssg
		return (0);
	}
	insert_space(str, redirect_idx, end, info);//리디렉션에 사용된 문자열 공백처리
	if (!redirection(name, info)) //받아온 파일 이름으로 파일 열어서 fd값 저장
	{
		free(name);
		return (0);
	}
	free(name);
	return (1);
}

int	set_fd(char *str, int start, t_info *info)
{
	char	*name;
	int		len;
	int		redirect_idx;
	int		end;

	redirect_idx = start++;//기호가 발견된 인덱스
	skip_space(str, &start);
	if (!str[start] || (str[start] && (str[start] == '<' || str[start] == '>'))) //기호로 끝나거나 연달아 기호가 올 경우
	{
		error_message(0, 1);
		return (-1);// error mssg에 추가
	}
	len = word_len(str, info, start, &end); //파일 이름 길이 알아내기
	if (len == 0 && info->redirect != 3) // ''같은 경우가  온 경우 <<에서만 가능, error mssg에 추가
	{
		error_message(0, 2);
		return (-1);
	}
	name = (char *)malloc(sizeof(char) * (len + 1));
	if (!name)
	{
		error_message(0, 0);
		return (-1);
	}
	name[len] = '\0';
	if (!check_string(str, name, len, start, info, redirect_idx, end))
		return (-1);
	return (end);
}

int	solve_redirect(char *str, t_info *info) //오류일 때 처리
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		info->redirect = 0;
		check_quote(str[i], &quote);
		if ((str[i] == '>' || str[i] == '<') && !quote)
		{
			if (str[i] == '<')
				info->redirect = 1;
			else
				info->redirect = 2;
			if (str[i + 1] && str[i + 1] == str[i])
			{
				info->redirect += 2;
				i = set_fd(str, i + 1, info) - 1;
			}
			else
				i = set_fd(str, i, info) - 1;
		}
		if (i == -2)
			return (0);
		i++;
	}
	return (1);
}