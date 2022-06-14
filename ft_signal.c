/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:52:33 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/13 16:48:32 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	ft_signal(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_num = 1;
	}
	if (signum == SIGQUIT)
	{
		g_exit_num = 127;
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

void	ft_here_doc_sig(int signum)
{
	if (signum == SIGINT)
	{
		exit(1);
	}
}

void	ft_here_doc_sig_parent(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		return ;
	}
}
