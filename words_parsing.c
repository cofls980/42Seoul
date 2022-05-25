#include "./includes/minishell.h"

// 따옴표를 고려하여 공백을 기준으로 분리된 단어 개수
int	find_word(char *str, int *start, int flag)
{
	int	i;
	int	cnt;
	int	word;
	int	quote;

	if (flag == -1)
		i = 0;
	else
		i = flag;
	cnt = 0;
	word = 0;
	quote = 0;
	while (str[i])
	{
		if (!word && !quote)
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i])
			{
				word = 1;
				*start = i;
				cnt++;
			}
			else
				break ;
		}
		if (!quote && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote && (str[i] == '\"' || str[i] == '\'') && quote == str[i])
			quote = 0;
		if (str[i + 1] && str[i + 1] == ' ' && !quote)
		{
			word = 0;
			if (flag != -1 && i++)
				break ;
		}
		i++;
	}
	if (flag != -1)
		return (i);
	return (cnt);
}

void	fill_strs(char *res, char *str, int start, int end)
{
	int i;

	i = 0;
	while (start < end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = 0;
}

char	**split_words(char *str)
{
	int cnt;
	int start;
	int	len;
	int	i;
	char	**res;

	cnt = find_word(str, &start, -1); // 단어 개수
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!res)
		return (0);
	i = 0;
	start = 0;
	while (i < cnt)
	{
		res[i] = (char *)malloc(sizeof(char) * (find_word(str, &start, start) - start + 1));
		if (!res[i])
		{
			free_str(res);
			return (0);
		}
		fill_strs(res[i], str, start, find_word(str, &start, start));
		start += find_word(str, &start, start);
		i++;
	}
	res[i] = 0;
	return (res);
}