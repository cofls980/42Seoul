/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:52:34 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 16:02:24 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo_print(char **command, int i, int option, t_info *info)
{
	while (command[i])
	{
		ft_print(info, command[i]);
		if (command[i + 1])
			ft_print(info, " ");
		i++;
	}
	if (option == -1)
		ft_print(info, "\n");
}

int	ft_echo(char **command, t_info *info)
{
	int		i;
	int		j;
	int		option;

	option = -1;
	i = 0;
	while (command[++i])
	{
		if (command[i][0] == '-' && command[i][1] == 'n')
		{
			j = 1;
			while (command[i][++j])
			{
				if (command[i][j] != 'n')
					break ;
			}
			if (command[i][j])
				break ;
		}
		else
			break ;
		option = i;
	}
	echo_print(command, i, option, info);
	return (0);
}
