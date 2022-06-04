#include "../includes/minishell.h"

char	*make_new_word(char *str, t_info *info, int *e) // 따옴표, $를 해석하여 새로운 문자열 생성
{
	char	*res;
	int		len;
	int		end;

	len = word_len(str, info, 0, &end); //새로 만들어질 문자열 길이 구함 & end 도 구함.
	if (len == 0) // '', "", $"" 같은 경우 ===> 에러처리 더 정확히 해야함.
	{
		*e = 1;
		return (0);
	}
	res = (char *)malloc(sizeof(char) * (len + 1));//추가 처리 필요
	if (!res)// 이떄 입력된 모든 문자열 실행을 멈출지 아님 현재 명령어에 대해서만 멈춰야하는지 고민
	{
		error_message(0, 0);
		return (0);
	}
	res[len] = '\0';
	change_word(res, 0, len, str, info);
	free(str);
	return (res);
}

int	have_to_change(char *str) // 따옴표 혹은 $ 기호가 있는지 확인
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	interpret_quotes(char **small, t_info *info)
{
	int	i;
	int	e;
	
	i = 0;
	e = 0;
	while (small[i])
	{
		if (have_to_change(small[i]))
		{
			small[i] = make_new_word(small[i], info, &e);//return 0일 때 처리 필요
			if (e && i == 0)
				return (1);
		}
		//printf("[%s]\n", small[i]);//문자열에 \0이 들어가있으므로 문자열 존재한다.
		i++;
	}
	return (0);
}