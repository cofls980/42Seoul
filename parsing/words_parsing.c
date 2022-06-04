#include "../includes/minishell.h"

// 따옴표를 고려하여 공백을 기준으로 분리된 단어 개수
int	count_word(char *str)
{
	int	i;
	int	cnt;
	int	word;
	int	quote;

	i = 0;
	cnt = 0;
	word = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !word)
		{
			cnt++;
			//printf("c: %c\n", str[i]);
			word = 1;
		}
		check_quote(str[i], &quote);
		if (str[i] == ' ' && word && !quote)
			word = 0;
		i++;
	}
	return (cnt);
}

int	find_word(char *str, int *start)
{
	int	i;
	int	word;
	int	quote;

	skip_space(str, start);
	i = *start;
	word = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !word)
		{
			//printf("f_c: %c\n", str[i]);
			word = 1;
		}
		check_quote(str[i], &quote);
		if (str[i] == ' ' && word && !quote)
			break ;
		i++;
	}
	return (i);
}

char	**split_words(char *str)
{
	int		cnt;
	int		start;
	int		end;
	int		i;
	char	**res;

	cnt = count_word(str); // 단어 개수
	//printf("cnt: %d\n", cnt);
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!res)
	{
		error_message(0, 0);
		return (0);
	}
	init_str(res, cnt + 1);
	i = 0;
	start = 0;
	while (i < cnt)
	{
		end = find_word(str, &start);
		res[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!res[i])
		{
			error_message(res, 0);
			return (0);
		}
		fill_word(str, res[i], start, end);
		start = end;
		i++;
	}
	/*i = 0;
	while (res[i])
		printf("str: %s\n", res[i++]);*/
	return (res);
}