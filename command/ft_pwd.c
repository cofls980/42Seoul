/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:53:04 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 15:58:36 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(char **cmd, t_info *info)
{
	int		i;
	char	*path;

	if (cmd[1])
	{
		i = 0;
		if (cmd[1][i] == '-')
		{
			cmd[1][i + 2] = 0;
			ft_print_error(cmd[0], cmd[1], "invalid option");
			return (1);
		}
	}
	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_print_error(cmd[0], cmd[1], strerror(errno));
		return (1);
	}
	ft_print(info, path);
	ft_print(info, "\n");
	free(path);
	return (0);
}
