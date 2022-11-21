#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_info
{
	char	**envp;
	char	**argv;
	int		argc;
}				t_info;

int		main(int argc, char *argv[], char *envp[]);
char	*find_path(char *command, char **envp);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	display_error(char *str);
void	close_fd(int fd);
int		open_file(char *file, int num);
void	duplicate(int fd, int dup_fd);
void	free_str(char **en_paths);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
int		get_next_line(int fd, char **line, int buf_size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void    pipex(t_info info, int outfilefd, int size, int start);
pid_t	command(t_info info, int index);
int		command_outfile(t_info info, int outfilefd, int index);
void	execute(t_info info, int index);

#endif
