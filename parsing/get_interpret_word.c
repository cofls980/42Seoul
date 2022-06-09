/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_interpret_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 05:30:45 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 05:30:45 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (is_valid_character(bundle[i]) || \
	('0' <= bundle[i] && bundle[i] <= '9'))
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

void	interpret(char *bundle, char *res, t_info *info, t_data *data)
{
	if (!data->quote && bundle[data->start + 1] && \
	is_quote(bundle[data->start + 1]))
		;
	else if (bundle[data->start + 1] && bundle[data->start + 1] == '?')
	{
		get_exit_status(res, &(data->r_idx), g_exit_num);
		(data->start)++;
	}
	else if (!bundle[data->start + 1] || is_space(bundle[data->start + 1]) || \
	!is_valid_character(bundle[data->start + 1]))
		res[(data->r_idx)++] = bundle[data->start];
	else
		insert_value(res, get_env_value(bundle, &(data->start), info), \
		&(data->r_idx));
}

void	get_interpret_word(char *bundle, char *res, t_info *info, t_word w_info)
{
	t_data	data;

	data.r_idx = 0;
	data.quote = 0;
	data.start = w_info.start;
	while (bundle[data.start] && data.r_idx < w_info.len)
	{
		check_quote(bundle[data.start], &(data.quote));
		if (data.quote && is_quote(bundle[data.start]) && \
		data.quote != bundle[data.start])
			res[(data.r_idx)++] = bundle[data.start];
		else if (bundle[data.start] == '$' && \
		((data.quote && data. quote == '\"') || !data.quote))
		{
			interpret(bundle, res, info, &data);
		}
		else if (!is_quote(bundle[data.start]))
			res[(data.r_idx)++] = bundle[data.start];
		(data.start)++;
	}
}
