#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>
//tcgetattr, tcsetattr
//int tcsetattr(int fildes, int optional_actions, struct termios *termios_p);

typedef struct s_list
{
	char	*key;
	char	*value;
	int		print;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	char	*home;
	char	**envp;
	t_list	*list;
}	t_info;

void	init(t_info *info, char **envp);
char	**ft_split(char const *s, char c);
char	*find_path(char *command, char **envp);
void	free_str(char **en_paths);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *str);
void	ft_echo(char **command);
t_list	*new_item(char *key, char *value, int print);
void	delete_item(t_list *item);
void	list_insert(t_list **list, t_list *item);
void	list_remove(t_list **list, char *key);
int		is_empty(t_list **list);
void	ft_env(t_info *info);
void	ft_export(char **command, t_info *info);
char	**split_equal(char *str);
char	**split_words(char *str);
char	**split_pipe(char *str);
int		find_pipes(char *str, int flag);
void	ft_pwd(char **cmd, t_info *info);
void	check_command(char **command, t_info *info);
void	ft_unset(char **cmd, t_info *info);
char	*list_find(t_list **list, char *key);
void	interpret_quotes(char **small, t_info *info);
void	running_execute(char **command, t_info *info);
void	signal_handler(int signal);
void	change_word(char *res, int len, char *str, t_info *info);
int		check_env_var(char *str, int start);
int		is_valid_name(char c);

#endif