#include "../includes/minishell.h"

//flag == -1 ---> 파이프 개수 반환, flag != -1 ---> flag위치부터 탐색하여 파이프 위치 반환
int	count_pipes(char *str)
{
	int	i;
	int	cnt;
	int quote;

	i = 0;
	cnt = 0;
	quote = 0;
	while (str[i])
	{
		check_quote(str[i], &quote);
		if (str[i] == '|' && !quote)
			cnt++;
		i++;
	}
	if (quote)
		return (-1);
	return (cnt);
}

int	find_string(char *str, int start)
{
	int	i;
	int quote;

	/*while (str[start] && str[start] == ' ')
		start++;*/
	i = start;
	quote = 0;
	while (str[i])
	{
		check_quote(str[i], &quote);
		if (str[i] == '|' && !quote)
			break ;
		i++;
	}
	return (i);
}

char	**split_with_pipe(char *str, char **res, t_info *info)
{
	int		i;
	int		start;
	int		end;

	i = -1;
	start = 0;
	while (++i <= info->pipe_count)
	{
		skip_space(str, &start);
		if (!str[start] || str[start] == '|') // 파이프가 연속으로 나오거나 파이프로 끝난 경우
		{
			error_message(res, 1);
			return (0);
		}
		end = find_string(str, start);
		res[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!res[i])
		{
			error_message(res, 0);
			return (0);
		}
		fill_word(str, res[i], start, end);
		start = end + 1;
	}
	return (res);
}

char	**split_pipe(char *str, t_info *info)
{
	char	**res;//size: pipe count + 1 + 1

	info->pipe_count = count_pipes(str);
	if (info->pipe_count == -1) // 따옴표 짝이 안 맞을 경우 error mssg
	{
		error_message(0, 2);
		return (0);
	}
	res = (char **)malloc(sizeof(char *) * (info->pipe_count + 2));
	if (!res)
	{
		error_message(0, 1);
		return (0);
	}
	init_str(res, info->pipe_count + 2);
	return (split_with_pipe(str, res, info));
}
