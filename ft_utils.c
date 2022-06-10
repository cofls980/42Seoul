/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:59:12 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/10 16:47:08 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	ft_print_error(char *cmd, char *arg, char *msg)
{
	int	fd;

	fd = 2;
	write(fd, "bash: ", 6);
	if (cmd != 0)
	{
		write(fd, cmd, ft_strlen(cmd));
		write(fd, ": ", 2);
	}
	if (arg != 0)
	{
		write(fd, arg, ft_strlen(arg));
		write(fd, ": ", 2);
	}
	write(fd, msg, ft_strlen(msg));
	write(fd, "\n", 1);
}

void	ft_error(int exit_status, t_info *info)
{
	//struct termios	new_term;

	/*tcgetattr(0, &new_term);
	new_term.c_lflag |= (ECHOCTL); //왜 사용했는지 물어보기
	tcsetattr(0, TCSANOW, &new_term);*/
	free_all(info);
	exit(exit_status);
}

void	ft_oldpwd(t_list *env, char *path)
{
	char	*new_path;
	t_list	*new1;
	t_list	*new2;

	new1 = env;
	new_path = getcwd(NULL, 0);
	if (list_find(&new1, "OLDPWD"))
	{
		list_insert(&(env), new_item(ft_strdup("OLDPWD"), ft_strdup(path), 1));
	}
	if (list_find(&new2, "PWD"))
	{
		list_insert(&(env), new_item(ft_strdup("PWD"), ft_strdup(new_path), 1));
	}
}
