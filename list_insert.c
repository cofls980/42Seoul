/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:51:11 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 16:44:56 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	list_insert(t_list **list, t_list *item)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, item->key) == 0)
			{
				tmp->value = ft_strdup(item->value);
				delete_item(item);
				break ;
			}
			tmp = tmp->next;
		}
		if (!tmp)
		{
			tmp = (*list);
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = item;
		}
	}
	else
		(*list) = item;
}

void	list_insert_for_export(t_list **list, t_list *item)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		while (tmp)
		{
			if (tmp == *list && ft_strcmp(tmp->key, item->key) > 0)
			{
				item->next = tmp;
				(*list) = item;
				break ;
			}
			else if (ft_strcmp(tmp->key, item->key) < 0 && (!tmp->next || ft_strcmp(tmp->next->key, item->key) > 0))
			{
				item->next = tmp->next;
				tmp->next = item;
				break ;
			}
			tmp = tmp->next;
		}
		if (!tmp)
		{
			tmp = (*list);
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = item;
		}
	}
	else
		(*list) = item;
}
