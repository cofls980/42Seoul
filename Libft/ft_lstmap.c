/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:29:51 by chaekim           #+#    #+#             */
/*   Updated: 2021/06/10 14:39:49 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		del(*lst);
		free(*lst);
		*lst = tmp;
	}
}

t_list	*ft_new(void *content)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list) * 1)))
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !(node = ft_new(f(lst->content))))
		return (0);
	new = node;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_new(f(lst->content))))
		{
			ft_clear(&node, del);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	return (node);
}
