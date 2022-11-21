#include "./includes/minishell.h"

void	init_ctrl(void)
{
	struct termios	term;

	signal(SIGINT, ft_signal);
	signal(SIGQUIT, ft_signal);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	init_env(t_info *info, char **envp)
{
	int		i;
	int		flag;
	char	**envp_item;

	info->bundles = 0;
	info->env_list = 0;
	info->envp = envp;
	info->pids = 0;
	envp_item = 0;
	info->input_fd = 0;
	info->output_fd = 1;
	i = -1;
	while (envp[++i])
	{
		envp_item = parsing_equal(envp[i], &flag);
		if (!envp_item)
			free_exit(info);
		list_insert(&(info->env_list), new_item(ft_strdup(envp_item[0]), \
		ft_strdup(envp_item[1]), 1));
		free_str(envp_item);
	}
	if (list_find(&(info->env_list), "OLDPWD") == 0)
		list_insert(&(info->env_list), \
		new_item(ft_strdup("OLDPWD"), 0, 0));
	return (1);
}

void	init_reset(t_info *info)
{
	info->bundles = 0;
	info->pids = 0;
	info->pipe_num = 0;
	info->have_pipe = 0;
	if (info->input_fd != 0)
		close_fd(info->input_fd, info);
	if (info->output_fd != 1)
		close_fd(info->output_fd, info);
	info->input_fd = 0;
	info->output_fd = 1;
}

void	init_after_pipe(t_info *info, int i)
{
	info->r_in_fd = -1;
	info->r_out_fd = -1;
	info->r_kind = 0;
	info->here_doc = 0;
	info->pids[i] = -2;
	info->command_null = 0;
	info->is_null = 0;
	info->word_num = 0;
}
