#include "./includes/minishell.h"

int	check_env_var(char *str, int start)
{
	if (str[start] == '0')// ./minishell
		return (11);
	else if (('1' <= str[start] && str[start] <= '9') || str[start] == '*' || str[start] == '@')//아무것도 없음
		return (0);
	else if (str[start] == '#')//0
		return (1);
	return (-1);
}

int	is_valid_name(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_' || ('0' <= c && c <= '9'));
}

int	get_env_var_len(char *str, int *start, t_info *info)
{
	int		i;
	int		check;
	char	c;
	char	*value;
	
	if (!str[*start + 1])
		return (1);
	(*start)++;
	check = check_env_var(str, *start);
	if (check != -1)
		return (check);
	i = *start;
	if (!is_valid_name(str[i]))//$특수기호 출력 ex) $%
		return (2);
	while (is_valid_name(str[i]))
		i++;
	c = str[i];
	str[i] = 0;
	value = list_find(&(info->list), str + *start);
	str[i] = c;
	*start = i - 1;
	return (ft_strlen(value));
}

int	new_word_len(char *str, t_info *info)
{
	int	i;
	int	quote;
	int	len;

	i = 0;
	quote = 0;
	len = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote && (str[i] == '\"' || str[i] == '\'') && quote == str[i])
			quote = 0;
		else if (str[i] == '$' && ((quote && quote == '\"') || !quote))
			len += get_env_var_len(str, &i, info);
		else
			len++;
		i++;
	}
	return (len);
}

char	*need_to_change(char *str, t_info *info) // 따옴표, $를 해석하여 새로운 문자열 생성
{
	char	*res;
	int		i;
	int		len;

	len = new_word_len(str, info); //새로 만들어질 문자열 길이 구함
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	change_word(res, len, str, info);
	res[len] = 0;
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

void	interpret_quotes(char **small, t_info *info)
{
	int	i;
	
	i = 0;
	while (small[i])
	{
		if (have_to_change(small[i]))
			small[i] = need_to_change(small[i], info);//return 0일 때 처리 필요
		i++;
	}
}