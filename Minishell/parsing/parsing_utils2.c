#include "../includes/minishell.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	is_space(char c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

int	is_redirect(char c)
{
	return (c == '<' || c == '>');
}
