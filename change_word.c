#include "./includes/minishell.h"

void	adapt_specific(char *res, int *idx, char *str, int start)
{
	char	*name;
	int		i;

	if (str[start] == '0')// ./minishell
	{
		name = "./minishell";
		i = 0;
		while (name[i])
		{
			res[*idx] = name[i];
			(*idx)++;
			i++;
		}
	}
	else if (str[start] == '#')//0
	{
		res[*idx] = '0';
		(*idx)++;
	}
}

void	insert_adapt(char *res, int *idx, char *str, int *start, t_info *info)
{
	int	i;
	int		j;
	int	check;
	char	c;
	char	*value;
	
	if (!str[*start + 1])
	{
		res[*idx] = '$';
		(*idx)++;
		return;
	}
	(*start)++;
	check = check_env_var(str, *start);
	if (check != -1)
	{
		adapt_specific(res, idx, str, *start);
		return ;
	}
	i = *start;
	if (!is_valid_name(str[i]))//$특수기호 출력 ex) $%
	{
		res[*idx] = '$';
		(*idx)++;
		res[*idx] = str[i];
		(*idx)++;
		return ;
	}
	while (is_valid_name(str[i]))
		i++;
	c = str[i];
	str[i] = 0;
	value = list_find(&(info->list), str + *start);
	if (value)
	{
		j = 0;
		while (value[j])
		{
			res[*idx] = value[j];
			(*idx)++;
			j++;
		}
	}
	str[i] = c;
	*start = i - 1;
	return ;
}

void	change_word(char *res, int len, char *str, t_info *info) // quote_var_parsing.c의 int new_word_len(char *str, t_info *info)와 비슷
{
	int	i;
	int	idx;
	int	quote;
	
	i = 0;
	idx = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote && (str[i] == '\"' || str[i] == '\'') && quote == str[i])
			quote = 0;
		else if (str[i] == '$' && ((quote && quote == '\"') || !quote))
			insert_adapt(res, &idx, str, &i, info);
		else
			res[idx++] = str[i];
		i++;
	}
}