/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 07:33:57 by chaekim           #+#    #+#             */
/*   Updated: 2022/06/10 18:31:51 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <errno.h>
//tcgetattr, tcsetattr
//int tcsetattr(int fildes, int optional_actions, struct termios *termios_p);

# define INPUT_R 1
# define OUTPUT_R 2
# define HERE_DOC_R 3
# define APPEND_R 4
# define MAXSIZE 1024

int	g_exit_num;

typedef struct s_list // 환경 변수를 위한 리트스 구조체
{
	char			*key;
	char			*value;
	int				print;
	struct s_list	*next;
}	t_list;

typedef struct s_word
{
	int	start;
	int	end;
	int	len;
}	t_word;

typedef struct s_data
{
	int	quote;
	int	r_idx;
	int	start;
}	t_data;

typedef struct s_info
{
	char	**envp;
	char	**bundles;
	int		pipe_num;
	int		have_pipe;
	int		r_kind;
	int		r_in_fd;
	int		r_out_fd;
	int		output_fd;
	int		input_fd;
	int		exit;
	int		here_doc;
	pid_t	*pids;
	t_list	*env_list;
}	t_info;

void	init_ctrl(void);
void	ft_signal(int signum);
void	ft_here_doc_sig(int signum);
void	ft_here_doc_sig_parent(int signum);
int		init_env(t_info *info, char **envp);
void	init_reset(t_info *info);
void	free_exit(t_info *info);

int		check_syntax(char *input, t_info *info);
char	**pipe_parsing(char *input, t_info *info);
int		solve_redirect(char *bundle, t_info *info);
int		here_doc(char *limit, t_info *info);
char	**parsing_words(char *bundle, t_info *info);
int		interpret_word(char **parts, t_info *info);
char	**parsing_equal(char *str, int *flag);
int		parse_redirect(char *bundle, char *name, t_info *info, t_word w_info);

int		get_word_len(char *bundle, t_info *info, int idx, int *end);
void	get_interpret_word(char *bundle, char *res, \
t_info *info, t_word w_info);
int		is_valid_character(char c);
int		is_space(char c);
int		is_quote(char c);
int		is_redirect(char c);
void	skip_space(char *str, int *start);
void	check_quote(char c, int *quote);
void	fill_word(char *str, char *res, int start, int end);

pid_t	command(char **command, t_info *info);
int		ft_echo(char **command, t_info *info);
int		ft_env(char **command, t_info *info);
int		ft_export(char **command, t_info *info);
int		ft_unset(char **cmd, t_info *info);
int		ft_cd(char **command, t_info *info);
int		ft_exit(char **command, t_info *info);
int		ft_pwd(char **cmd, t_info *info);
void	ft_print(t_info *info, char *str);
void	set_output_fd(t_info *info);
void	set_input_fd(t_info *info);
int		is_builtin(char *command);
int		builtin_command(char **command, t_info *info);
int		is_key_valid(char *str);
int		have_equal(char *str);
void	print_declare(t_info *info, char *key, char *value);
void	export_print(int i, t_info *info);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *str);

t_list	*new_item(char *key, char *value, int print);
void	delete_item(t_list *item);
void	list_insert(t_list **list, t_list *item);
char	*list_find(t_list **list, char *key);
void	list_remove(t_list **list, char *key);
void	list_insert_for_export(t_list **list, t_list *item);

void	ft_print_error(char *cmd, char *arg, char *msg);
void	ft_error(int exit_status, t_info *info);
void	free_str(char **en_paths);
void	init_str(char **strs, int len);
void	free_all(t_info *info);
void	free_list(t_list **list);

char	*find_path(char *command, char **envp);
void	ft_oldpwd(t_list *env, char *path);
void	init_after_pipe(t_info *info, int i);

#endif