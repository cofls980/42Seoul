#include "../includes/minishell.h"

void	adapt_specific(char *res, int *idx, char *str, int start)
{
	char	*name;
	int		i;

	if (str[start] == '0')// ./minishell
	{
		name = "./minishell";
		i = 0;
		while (name[i])
		{
			res[*idx] = name[i];
			(*idx)++;
			i++;
		}
	}
	/*else if (str[start] == '#')//0
	{
		res[*idx] = '0';
		(*idx)++;
	}*/
}

void	insert_value(char *res, char *value, int *idx)
{
	int	i;

	if (!value) //문자열이 있는지 확인하기
		return ;
	i = 0;
	while (value[i])
	{
		res[*idx] = value[i];
		(*idx)++;
		i++;
	}
}

void	insert_adapt(char *res, int *idx, char *str, int *start, t_info *info)
{
	int		i;
	int		check;
	char	c;
	char	*value;
	
	(*start)++;
	check = check_env_var(str, *start);
	if (check != -1)
	{
		adapt_specific(res, idx, str, *start);
		return ;
	}
	i = *start;
	if (!is_valid_name(str[i]))//$특수기호 출력 ex) $% , 숫자가 나오면 어떻게 처리할 지 생각
	{
		res[(*idx)++] = '$';
		res[(*idx)++] = str[i];
		return ;
	}
	while (is_valid_name(str[i]) || ('0' <= str[i] && str[i] <= '9'))
		i++;
	c = str[i];
	str[i] = 0;
	value = list_find(&(info->list), str + *start);
	insert_value(res, value, idx);
	str[i] = c;
	*start = i - 1;
	return ;
}
// similar.c의 int word_len(char *str, t_info *info)와 비슷
void	change_word(char *res, int s_idx, int len, char *str, t_info *info) //문자열 해석
{
	int	r_idx;
	int	quote;
	
	r_idx = 0;
	quote = 0;
	while (str[s_idx] && r_idx < len)
	{
		check_quote(str[s_idx], &quote);
		if (str[s_idx] == '$' && ((quote && quote == '\"') || !quote)) // $? 추가
		{
			if (!str[s_idx + 1] || str[s_idx + 1] == ' ' || str[s_idx + 1] == '<' || str[s_idx + 1] == '>') //$뒤가 공백이거나 문자열의 끝인 경우
				res[r_idx++] = str[s_idx]; // $넣음
			else if ((str[s_idx + 1] == '\'' || str[s_idx + 1] == '\"'))//$뒤에 따옴표가 오면 $ 무시
				;
			else
				insert_adapt(res, &r_idx, str, &s_idx, info);
		}
		else if (!is_quote(str[s_idx]))
		{
			res[r_idx++] = str[s_idx];
		}
		s_idx++;
	}
}
//환경변수 $$ https://melonicedlatte.com/2020/09/25/085200.html
//쉘 pid 값