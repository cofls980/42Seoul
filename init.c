#include "./includes/minishell.h"

void	init_ctrl()
{
	struct termios	term;

	signal(SIGINT, ft_signal);
	signal(SIGQUIT, ft_signal);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;//check
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	init_env(t_info *info, char **envp)
{
	int		i;
	int		flag;
	char	**envp_item;

	info->env_list = 0; // env를 위한 리스트
	i = 0;
	while (envp[i])
	{
		envp_item = split_equal(envp[i], &flag);
		if (!envp_item)
			return (0);
		list_insert(&(info->env_list), new_item(ft_strdup(envp_item[0]), ft_strdup(envp_item[1]), 1));
		free_str(envp_item);
		i++;
	}
	info->envp = envp;
	return (1);
}

void	init(t_info *info)
{
	info->home = ft_strdup(list_find(&(info->env_list), "HOME"));
	info->pwd = ft_strdup(list_find(&(info->env_list), "PWD"));
	g_exit_num = 0;
	info->bundles = 0;
}

void	init_reset(t_info *info)
{
	info->pipe_num = 0;
	info->have_pipe = 0;
	if (info->input_fd != 0)
		close(info->input_fd);
	info->input_fd = 0;
	if (info->output_fd != 1)
		close(info->output_fd);
	info->output_fd = 1;
	info->exit = 0;
}