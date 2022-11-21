/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:52:58 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/13 14:16:02 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	key_value_insert(char *command, char **envp_item, t_info *info)
{
	if (have_equal(command))
		list_insert(&(info->env_list), \
		new_item(ft_strdup(envp_item[0]), ft_strdup(envp_item[1]), 1));
	else
		list_insert(&(info->env_list), \
		new_item(ft_strdup(envp_item[0]), 0, 0));
}

int	export(char **command, int *status, int i, t_info *info)
{
	char	**envp_item;
	int		flag;

	flag = 0;
	envp_item = parsing_equal(command[i], &flag);
	if (envp_item && !is_key_valid(envp_item[0]))
	{
		key_value_insert(command[i], envp_item, info);
	}
	else
	{
		*status = 1;
		if (flag == 1)
		{
			free_str(envp_item);
			return (0);
		}
		ft_print_error(command[0], command[i], "not a valid identifier");
	}
	free_str(envp_item);
	return (1);
}

int	ft_export(char **command, t_info *info)
{
	int	i;
	int	status;

	if (command[1] && command[1][0] == '-')
	{
		command[1][2] = 0;
		ft_print_error(command[0], command[1], "invalid option");
		return (1);
	}
	i = 0;
	status = 0;
	while (command[++i])
	{
		if (!export(command, &status, i, info))
		{
			if (info->have_pipe == 0 && info->r_in_fd != -1)
				close_fd(info->r_in_fd, info);
			close_fd(info->output_fd, info);
			free_exit(info);
		}
	}
	if (status != 1)
		export_print(i, info);
	return (status);
}
