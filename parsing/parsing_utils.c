#include "../includes/minishell.h"

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

void	skip_space(char *str, int *start)
{
	while (str[*start] && str[*start] == ' ')
		(*start)++;
}

void	check_quote(char c, int *quote)
{
	if (!(*quote) && (c == '\"' || c == '\''))
		*quote = c;
	else if ((*quote) && (c == '\"' || c == '\'') && (*quote) == c)
		*quote = 0;
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}