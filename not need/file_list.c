#include "./includes/minishell.h"

t_redirect	*new_file(char *name, int kind)
{
	t_redirect *item;

	item = malloc(sizeof(t_redirect));
	item->name = name;
	item->redirect_kind = kind;
	item->next = 0;
	return (item);
}

void	insert_file_list(t_redirect **file, t_redirect *item)
{
	t_redirect *tmp;

	tmp = (*file);
	if (tmp)
	{}
	else
		(*file) = item;
}

void	delete_file(t_redirect *item)
{
	if (item)
	{
		item->next = 0;
		free(item->name);
		free(item);
	}
}

void	remove_all(t_redirect **file)
{
	t_redirect *tmp;
	t_redirect *item;

	tmp = (*file);
	if (tmp)
	{
		while (tmp)
		{
			item = tmp;
			tmp = tmp->next;
			delete_file(item);
		}
	}
}