#include "../includes/minishell.h"

void	fill_word(char *str, char *res, int start, int end)
{
	int	i;

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
	while (str[*start] && is_space(str[*start]))
		(*start)++;
}

void	check_quote(char c, int *quote)
{
	if (!(*quote) && (c == '\"' || c == '\''))
		*quote = c;
	else if ((*quote) && (c == '\"' || c == '\'') && (*quote) == c)
		*quote = 0;
}
