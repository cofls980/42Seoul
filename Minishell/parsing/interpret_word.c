/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 05:31:04 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/13 15:13:16 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	have_to_change(char *part)
{
	int	i;

	i = 0;
	while (part[i])
	{
		if (is_quote(part[i]) || part[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*make_new_word(char *part, t_info *info)
{
	int		end;
	char	*res;
	t_word	w_info;

	w_info.len = get_word_len(part, info, 0, &end);
	res = (char *)malloc(sizeof(char) * (w_info.len + 1));
	if (!res)
	{
		ft_print_error(0, 0, strerror(errno));
		return (0);
	}
	if (w_info.len == 0 && info->is_null == 1)
		info->command_null++;
	else
	{
		if (info->is_null)
			info->is_null = 0;
		res[w_info.len] = '\0';
		w_info.start = 0;
		get_interpret_word(part, res, info, w_info);
	}
	free(part);
	return (res);
}

void	check_part(char **parts, int i, t_info *info)
{
	if (!parts[i])
	{
		close_iofd(info);
		free_str(parts);
		free_exit(info);
	}
}

int	interpret_word(char **parts, t_info *info)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		if (have_to_change(parts[i]))
		{
			parts[i] = make_new_word(parts[i], info);
			check_part(parts, i, info);
			if (parts[i][0] == '\0')
			{
				if (info->is_null && (i == 0 || !parts[i - 1]))
				{
					free(parts[i]);
					parts[i] = 0;
				}
				info->is_null = 0;
			}
		}
		i++;
	}
	info->word_num = i;
	return (1);
}
