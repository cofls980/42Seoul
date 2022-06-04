#include "../includes/minishell.h"

//특수 기호를 $%의 경우처럼 처리할까
/*int	check_env_var(char *str, int start)
{
	if (str[start] == '0')// ./minishell
		return (11);
	else if (('1' <= str[start] && str[start] <= '9') || str[start] == '*' || str[start] == '@')//아무것도 없음
		return (0);
	else if (str[start] == '#')//0
		return (1);
	return (-1);
}*/

int	check_env_var(char *str, int start)
{
	if (str[start] == '0')// ./minishell
		return (11);
	else if ('1' <= str[start] && str[start] <= '9')//아무것도 없음
		return (0);
	return (-1);
}

int	is_valid_name(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_');
}

int	get_env_len(char *str, int *start, t_info *info)//$도 같이 들어옴
{
	int		i;
	int		check;
	char	c;
	char	*value;
	
	(*start)++;
	check = check_env_var(str, *start);
	if (check != -1)
		return (check);
	i = *start;
	if (!is_valid_name(str[i]))//$특수기호 출력 ex) $% $다음에 바로 특수문자나 숫자가 오면 안된다.
		return (2);
	while (is_valid_name(str[i]) || ('0' <= str[i] && str[i] <= '9'))
		i++;
	c = str[i];
	str[i] = 0;
	value = list_find(&(info->list), str + *start);
	str[i] = c;
	*start = i - 1;
	return (ft_strlen(value));
}

int	word_len(char *str, t_info *info, int idx, int *end)
{
	int	quote;
	int	len;

	quote = 0;
	len = 0;
	while (str[idx])
	{
		check_quote(str[idx], &quote);
		if (str[idx] == '$' && ((quote && quote == '\"') || !quote))
		{
			if (!str[idx + 1] || str[idx + 1] == ' ' || str[idx + 1] == '<' || str[idx + 1] == '>' || (quote && is_quote(str[idx + 1]))) //$뒤가 공백이거나 문자열의 끝인 경우
				len += 1;
			else if (!quote && is_quote(str[idx + 1]))
				len += 0;
			else
				len += get_env_len(str, &idx, info);
		}
		else if (!quote && (str[idx] == ' ' || str[idx] == '<' || str[idx] == '>'))
			break;
		else if (!is_quote(str[idx]))
			len++;
		idx++;
	}
	*end = idx;
	return (len);
}