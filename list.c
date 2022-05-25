#include "./includes/minishell.h"

t_list	*new_item(char *key, char *value, int print)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	res->key = key;
	res->value = value;
	res->print = print;
	res->next = NULL;
	return (res);
}

void	delete_item(t_list *item)
{
	if (item)
	{
		item->next = NULL;
		free(item->key);
		free(item->value);
		free(item);
	}
}

void	list_insert(t_list **list, t_list *item)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*item_tmp;

	tmp = (*list);
	if (tmp)
	{
		prev = (*list);
		while (tmp)
		{
			if (ft_strcmp(tmp->key, item->key) == 0 && item->value)
			{
				item_tmp = tmp;
				prev->next = item;
				item->next = tmp->next;
				delete_item(item_tmp);
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		if (!tmp)
			prev->next = item;
	}
	else
		(*list) = item;
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

int	is_empty(t_list **list)
{
	if (*list)
		return (0);
	return (1);
}