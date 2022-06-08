#include "../includes/minishell.h"

void	insert_value(char *res, char *value, int *idx)
{
	int	i;

	if (!value)
		return ;
	i = 0;
	while (value[i])
	{
		res[*idx] = value[i];
		(*idx)++;
		i++;
	}
}

char	*get_env_value(char *bundle, int *start, t_info *info)
{
	int		i;
	char	c;
	char	*value;
	
	(*start)++;
	i = *start;
	while (is_valid_character(bundle[i]) || ('0' <= bundle[i] && bundle[i] <= '9'))
		i++;
	c = bundle[i];
	bundle[i] = 0;
	value = list_find(&(info->env_list), bundle + *start);
	bundle[i] = c;
	*start = i - 1;
	return (value);
}

void	get_exit_status(char *res, int *r_idx, int status)
{
	if (status >= 10)
		get_exit_status(res, r_idx, status / 10);
	res[(*r_idx)++] = (status % 10) + '0';
}

void	get_interpret_word(char *bundle, char *res, t_info *info, t_word w_info)
{
	int	r_idx;
	int	quote;
	int	start;
	
	r_idx = 0;
	quote = 0;
	start = w_info.start;
	while (bundle[start] && r_idx < w_info.len)
	{
		check_quote(bundle[start], &quote);
		if (quote && is_quote(bundle[start]) && quote != bundle[start])
			res[r_idx++] = bundle[start];
		else if (bundle[start] == '$' && ((quote && quote == '\"') || !quote))
		{
			if (!quote && bundle[start + 1] && is_quote(bundle[start + 1]))
				;
			else if (bundle[start + 1] && bundle[start + 1] == '?')
			{
				get_exit_status(res, &r_idx, g_exit_num);
				start++;
			}
			else if (!bundle[start + 1] || is_space(bundle[start + 1]) || !is_valid_character(bundle[start + 1]))
				res[r_idx++] = bundle[start];
			else
				insert_value(res, get_env_value(bundle, &start, info), &r_idx);
		}
		else if (!is_quote(bundle[start]))
			res[r_idx++] = bundle[start];
		start++;
	}
}