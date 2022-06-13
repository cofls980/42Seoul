/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 05:30:52 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/13 14:36:55 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_character(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_');
}

int	get_env_len(char *str, int *start, t_info *info)
{
	int		i;
	char	c;
	char	*value;

	(*start)++;
	i = *start;
	while (is_valid_character(str[i]) || ('0' <= str[i] && str[i] <= '9'))
		i++;
	c = str[i];
	str[i] = 0;
	value = list_find(&(info->env_list), str + *start);
	if (!value)
		info->is_null = 1;
	str[i] = c;
	*start = i - 1;
	return (ft_strlen(value));
}

int	get_exit_status_len(void)
{
	int	len;
	int	status;

	len = 0;
	status = g_exit_num;
	if (g_exit_num == 0)
		return (1);
	while (status)
	{
		status /= 10;
		len++;
	}
	return (len);
}

int	get_after_dollar(char *bundle, t_info *info, int quote, int *idx)
{
	int	len;

	len = 0;
	if (!quote && bundle[*idx + 1] && is_quote(bundle[*idx + 1]))
		len += 0;
	else if (bundle[*idx + 1] && bundle[*idx + 1] == '?')
	{
		len += get_exit_status_len();
		(*idx)++;
	}
	else if (!bundle[*idx + 1] || is_space(bundle[*idx + 1]) || \
	!is_valid_character(bundle[*idx + 1]))
		len += 1;
	else
		len += get_env_len(bundle, idx, info);
	return (len);
}

int	get_word_len(char *bundle, t_info *info, int idx, int *end)
{
	int	quote;
	int	len;

	quote = 0;
	len = 0;
	while (bundle[idx])
	{
		check_quote(bundle[idx], &quote);
		if (quote && is_quote(bundle[idx]) && quote != bundle[idx])
			len++;
		else if (bundle[idx] == '$' && ((quote && quote == '\"') || !quote))
		{
			len += get_after_dollar(bundle, info, quote, &idx);
		}
		else if (!quote && (is_space(bundle[idx]) || is_redirect(bundle[idx])))
			break ;
		else if (!is_quote(bundle[idx]))
			len++;
		idx++;
	}
	*end = idx;
	return (len);
}
