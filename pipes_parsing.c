#include "./includes/minishell.h"

//flag == -1 ---> 파이프 개수 반환, flag != -1 ---> flag위치부터 탐색하여 파이프 위치 반환
int	find_pipes(char *str, int flag)
{
	int	i;
	int	cnt;
	int quote;

	if (flag == -1)
		i = 0;
	else
		i = flag;
	cnt = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote && (str[i] == '\"' || str[i] == '\'') && quote == str[i])
			quote = 0;
		else if (str[i] == '|' && !quote)
		{
			if (flag != -1)
				break ;
			cnt++;
		}
		i++;
	}
	if (quote)
		return (-1);
	if (flag != -1)
		return (i);
	return (cnt);
}

void	fill_word(char *str, char *res, int start, int end) //words_parsing.c의 fill_word와 동일
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

char	**split_pipe(char *str)
{
	int		i;
	int		pipes_cnt;
	int		start;
	char	**res;//size: pipe count + 1 + 1

	pipes_cnt = find_pipes(str, -1);
	if (pipes_cnt == -1)
		return (0);
	res = (char **)malloc(sizeof(char *) * (pipes_cnt + 2));
	if (!res)
		return (0);
	i = 0;
	start = 0;
	while (i <= pipes_cnt)
	{
		res[i] = (char *)malloc(sizeof(char) * (find_pipes(str, start) - start + 1));
		if (!res[i])
		{
			free_str(res);
			return (0);
		}
		fill_word(str, res[i], start, find_pipes(str, start));
		start = find_pipes(str, start) + 1;
		i++;
	}
	res[i] = 0;
	return (res);
}
