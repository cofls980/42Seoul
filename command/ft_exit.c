/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:41:32 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/05 14:08:43 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_in_range(char *str)
{
	int			flag;
	int			i;
	long long	num;
	long long	temp;

	flag = 1;
	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		temp = (num * 10 + (flag) * (str[i] - '0'));
		i++;
		if ((flag == -1 && temp > num) || (flag == 1 && temp < num))
			return (0);
		else
			num = temp;
	}
	return (1);
}

static int	exit_non_numeric(char *str, t_info *info) //exit|exit kjdhfk --> exit $?
{
	ft_print(info, "exit\n");
	ft_print_error("exit", str,\
	"numeric argument required");
	//ft_error(255);
	return (255);
}

static long long	stoll(char *str)
{
	int			flag;
	int			i;
	long long	num;

	flag = 1;
	i = 0;
	num = 0;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		num = (num * 10 + (flag) * (str[i] - '0'));
		i++;
	}
	return (num);
}

int	ft_exit(char **command, t_info *info)
{
	g_exit_num = EXIT_FAILURE;
	if (command)
	{
		if (command[1] == 0)
		{
			ft_print(info, "exit\n");
			info->exit = 1;
			return (0);
		}
		if (command[2] == 0)
		{
			if (!is_digit(command[1]) || !is_in_range(command[1]))
				return (exit_non_numeric(command[1], info));
			g_exit_num = (unsigned char)stoll(command[1]);
			ft_print(info, "exit\n");
			if (command[1][0] == '\0')
				ft_print(info, "minishell: exit: : numeric argument required\n");
			ft_error(g_exit_num);//이 부분 살리기
		}
		ft_print_error("exit", 0, "too many arguments");
	}
	return (1);
}
