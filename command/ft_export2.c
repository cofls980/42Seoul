/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:52:58 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 18:42:50 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_key_valid(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (1);
	if ('0' <= str[0] && str[0] <= '9')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] == '_' || ('a' <= str[i] && str[i] <= 'z') \
		|| ('A' <= str[i] && str[i] <= 'Z') \
		|| ('0' <= str[i] && str[i] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

int	have_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && i != 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_declare(t_info *info, char *key, char *value)
{
	int		i;
	char	c;

	i = 0;
	ft_print(info, "declare -x ");
	ft_print(info, key);
	if (value)
	{
		ft_print(info, "=\"");
		while (value[i])
		{
			if (value[i] == '\"')
			{
				c = '\\';
				write(info->output_fd, &c, 1);
			}
			c = value[i];
			write(info->output_fd, &c, 1);
			i++;
		}
		ft_print(info, "\"");
	}
	ft_print(info, "\n");
}

void	export_print(int i, t_info *info)
{
	t_list	*list;
	t_list	*set;

	list = info->env_list;
	set = NULL;
	if (i == 1)
	{
		while (list)
		{
			if (ft_strcmp(list->key, "_") != 0)
				list_insert_for_export(&(set), new_item(ft_strdup(list->key), \
				ft_strdup(list->value), 1));
			list = list->next;
		}
		list = set;
		while (list)
		{
			print_declare(info, list->key, list->value);
			list = list->next;
		}
		free_list(&set);
	}
}
