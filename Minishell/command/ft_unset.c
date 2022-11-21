/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:53:11 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 15:58:15 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (1);
	if ('0' <= str[0] && str[0] <= '9')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(('a' <= str[i] && str[i] <= 'z') \
		|| ('A' <= str[i] && str[i] <= 'Z') \
		|| str[i] == '_' || ('0' <= str[i] && str[i] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(char **cmd, t_info *info)
{
	int	i;
	int	status;

	if (cmd[1] && cmd[1][0] == '-')
	{
		cmd[1][2] = 0;
		ft_print_error(cmd[0], cmd[1], "invalid option");
		return (1);
	}
	i = 1;
	status = 0;
	while (cmd[i])
	{
		if (is_valid(cmd[i]))
		{
			ft_print_error(cmd[0], cmd[i], "not a valid identifier");
			status = 1;
		}
		else
		{
			list_remove(&(info->env_list), cmd[i]);
		}
		i++;
	}
	return (status);
}
