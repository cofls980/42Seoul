#include "./includes/minishell.h"

int	insert(t_list **list, t_list *item)
{
	t_list	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (ft_strcmp(tmp->key, item->key) == 0)
		{
			if (item->print != 0)
			{
				if (tmp->value)
					free(tmp->value);
				tmp->value = ft_strdup(item->value);
				tmp->print = item->print;
				delete_item(item);
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	list_insert(t_list **list, t_list *item)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		if (insert(list, item))
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

int	insert_item(t_list **list, t_list *item)
{
	t_list	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp == *list && ft_strcmp(tmp->key, item->key) > 0)
		{
			item->next = tmp;
			(*list) = item;
			return (0);
		}
		else if (ft_strcmp(tmp->key, item->key) < 0 \
		&& (!tmp->next || ft_strcmp(tmp->next->key, item->key) > 0))
		{
			item->next = tmp->next;
			tmp->next = item;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	list_insert_for_export(t_list **list, t_list *item)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		if (insert_item(list, item))
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
