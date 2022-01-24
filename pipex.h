/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:55:25 by chaekim           #+#    #+#             */
/*   Updated: 2022/01/25 03:57:33 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_fdlist
{
	int		infilefd;
	int		outfilefd;
	char	*path1;
	char	*path2;
	char	**command1;
	char	**command2;
}				t_fdlist;

int		main(int argc, char *argv[], char *envp[]);
int		ft_fork(int fd[], int flag, t_fdlist *flist, char **envp);
void	child_process(int fd[], char **envp, int flag, t_fdlist *flist);
char	*find_path(char *command, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	print(char *str);
void	ft_error(char *mssg, t_fdlist *flist);
void	free_all(t_fdlist *flist);
void	free_path(char **en_paths);
void	init_flist(char **argv, char **envp, t_fdlist *flist);
char	**ft_split(char const *s, char c);
void	ft_cpy(char *str, char const *s, int start, int end);
void	ft_findword(char const *s, char c, int *start, int *end);
int		ft_wordcount(char const *s, char c);

#endif
