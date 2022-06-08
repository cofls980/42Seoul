#include "./includes/minishell.h"

int	is_valid_quote(char *input)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		check_quote(input[i], &quote);
		i++;
	}
	return (quote);
}

int	is_valid_pipe(char *input, t_info *info)
{
	int	i;
	int quote;

	i = 0;
	skip_space(input, &i);
	if (!input[i] || input[i] == '|')
		return (1);
	quote = 0;
	while (input[i])
	{
		check_quote(input[i], &quote);
		if (input[i] == '|' && !quote)
		{
			info->pipe_num++;
			i++;
			skip_space(input, &i);
			if (!input[i] || input[i] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_valid_redirect(char *input)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		check_quote(input[i], &quote);
		if ((input[i] == '<' || input[i] == '>') && !quote)
		{
			i++;
			if (input[i] && input[i] == input[i - 1])
				i++;
			skip_space(input, &i);
			if (!input[i] || input[i] == '<' || input[i] == '>' || input[i] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_syntax(char *input, t_info *info)
{
	if (is_valid_quote(input) != 0)
		return (1);
	if (is_valid_redirect(input) != 0)
		return (1);
	if (is_valid_pipe(input, info) != 0)
		return (1);
	return (0);
}