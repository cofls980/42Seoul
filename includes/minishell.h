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
# include <dirent.h>
//tcgetattr, tcsetattr
//int tcsetattr(int fildes, int optional_actions, struct termios *termios_p);

typedef struct s_list // 환경 변수를 위한 리트스 구조체
{
	char	*key;
	char	*value;
	int		print;
	struct s_list	*next;
}	t_list;

/*typedef struct s_word
{
	int		start;
	int		end;
	int		len;
	char	*str;
} t_word;*/

typedef struct s_info
{
	char	*home;
	char	**envp;
	int		pipe_count;
	int		have_pipe;
	int		redirect;
	int		redirect_in;//리디렉션 결과로 나오는 fd값 저장
	int		redirect_out;
	int		output_file;//초기0, 1의 숫자 또는 pipe할 때 사용하는 fd값 저장
	int		input_file;
	int		here_doc;
	int		error;
	pid_t	*pids;
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
void	ft_echo(char **command, t_info *info);
t_list	*new_item(char *key, char *value, int print);
void	delete_item(t_list *item);
void	list_insert(t_list **list, t_list *item);
void	list_remove(t_list **list, char *key);
int		is_empty(t_list **list);
void	ft_env(t_info *info);
void	ft_export(char **command, t_info *info);
char	**split_equal(char *str);
char	**split_words(char *str);
char	**split_pipe(char *str, t_info *info);
int		find_pipes(char *str, int flag);
void	ft_pwd(char **cmd, t_info *info);
int		builtin_command(char **command, t_info *info);
void	ft_unset(char **cmd, t_info *info);
char	*list_find(t_list **list, char *key);
int		interpret_quotes(char **small, t_info *info);
pid_t	last_execute(char **command, t_info *info);
void	signal_handler(int signal);
void	change_word(char *res, int start, int len, char *str, t_info *info);
int		check_env_var(char *str, int start);
int		is_valid_name(char c);
int		solve_redirect(char *str, t_info *info);
int		word_len(char *str, t_info *info, int start, int *end);
int		is_quote(char c);
int		get_next_line(int fd, char **line, int buf_size);
int		here_doc(char *limit, t_info *info);
void	execute(char **command, char **envp);
pid_t	command(char **command, t_info *info);
void	init_str(char **strs, int len);
void	skip_space(char *str, int *start);
void	check_quote(char c, int *quote);
void	error_message(char **strs, int flag);
void	fill_word(char *str, char *res, int start, int end);
void	set_redirection(t_info *info);
void	ft_write(t_info *info, char *str);

#endif