/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:22:29 by chaekim           #+#    #+#             */
/*   Updated: 2022/01/25 04:03:20 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int fd[], char **envp, int flag, t_fdlist *flist)
{
	if (flag == 1)
	{
		close(fd[0]);
		if (dup2(flist->infilefd, STDIN_FILENO) == -1)
			ft_error("dup2 error", 0);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("dup2 error", 0);
		close(flist->infilefd);
		close(fd[1]);
		if (execve(flist->path1, flist->command1, envp) == -1)
			ft_error("first execve error", 0);
	}
	else if (flag == 2)
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("dup2 error", 0);
		if (dup2(flist->outfilefd, STDOUT_FILENO) == -1)
			ft_error("dup2 error", 0);
		close(fd[0]);
		close(flist->outfilefd);
		if (execve(flist->path2, flist->command2, envp) == -1)
			ft_error("second execve error", 0);
	}
}

int	ft_fork(int fd[], int flag, t_fdlist *flist, char **envp)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_error("pipe error", flist);
	else if (pid == 0)
		child_process(fd, envp, flag, flist);
	return (pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_fdlist	flist;
	int			fd[2];
	int			pid[2];

	if (argc != 5)
	{
		print("Error: need more parameters\n");
		return (1);
	}
	init_flist(argv, envp, &flist);
	flist.infilefd = open(argv[1], O_RDONLY);
	if (flist.infilefd == -1)
		ft_error("file open error", &flist);
	flist.outfilefd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (flist.outfilefd == -1)
		ft_error("file open error", &flist);
	if (pipe(fd) == -1)
		ft_error("pipe error", &flist);
	pid[0] = ft_fork(fd, 1, &flist, envp);
	pid[1] = ft_fork(fd, 2, &flist, envp);
	waitpid(pid[1], NULL, 0);
	waitpid(pid[0], NULL, 0);
	free_all(&flist);
	return (0);
}
