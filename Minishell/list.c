/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:51:50 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 18:57:43 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

t_list	*new_item(char *key, char *value, int print)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	res->key = key;
	res->value = value;
	res->print = print;
	res->next = 0;
	return (res);
}

void	delete_item(t_list *item)
{
	if (item)
	{
		if (item->key != 0)
			free(item->key);
		if (item->value != 0)
			free(item->value);
		free(item);
	}
}

void	list_remove(t_list **list, char *key)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*item;

	tmp = (*list);
	if (tmp)
	{
		prev = (*list);
		while (tmp)
		{
			if (ft_strcmp(tmp->key, key) == 0)
			{
				item = tmp;
				prev->next = tmp->next;
				delete_item(item);
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

int	list_valid_key(t_list **list, char *key)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, key) == 0)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

char	*list_find(t_list **list, char *key)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, key) == 0)
				return (tmp->value);
			tmp = tmp->next;
		}
	}
	return (0);
}
