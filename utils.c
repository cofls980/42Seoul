/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:51:54 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 18:32:59 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	free_str(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	init_str(char **strs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		strs[i] = 0;
		i++;
	}
}

void	free_list(t_list **list)
{
	t_list	*item;

	if (*list)
	{
		while (*list)
		{
			item = *list;
			*list = (*list)->next;
			delete_item(item);
		}
		free(*list);
	}
}

void	free_all(t_info *info)
{
	if (info->bundles)
		free_str(info->bundles);
	if (info->pids)
		free(info->pids);
	free_list(&(info->env_list));
}

void	free_exit(t_info *info)
{
	free_all(info);
	exit(1);
}
