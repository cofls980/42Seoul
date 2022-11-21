#include "./includes/minishell.h"

void	free_pid(t_info *info)
{
	int	i;
	int	status;
	int	e_num;

	i = 0;
	e_num = -1;
	while (i < info->have_pipe + 1)
	{
		if (check_pid(&i, &e_num, info))
			continue ;
		if (waitpid(info->pids[i++], &status, 0) == -1)
		{
			close_iofd(info);
			free_exit(info);
		}
		e_num = (status & 0xff00) >> 8;
	}
	if (info->here_doc)
	{
		free(info->pids);
		return ;
	}
	if (e_num != -1)
		g_exit_num = e_num;
	free(info->pids);
}

void	parsing(char **bundles, t_info *info)
{
	int		i;
	char	**parts;

	info->have_pipe = info->pipe_num;
	i = -1;
	while (bundles[++i])
	{
		init_after_pipe(info, i);
		parts = 0;
		if (solve_redirect(bundles[i], info) != -2)
		{
			parts = parsing_words(bundles[i], info);
			if (parts && interpret_word(parts, info))
				info->pids[i] = command(parts, info);
			else
				g_exit_num = 1;
		}
		else
			g_exit_num = 1;
		info->pipe_num--;
		words_free(parts, info);
	}
}

void	minishell(char *input, t_info *info)
{
	if (check_syntax(input, info))
	{
		ft_print_error(0, 0, "syntax error near unexpected token");
		g_exit_num = 258;
		return ;
	}
	info->bundles = pipe_parsing(input, info);
	if (!(info->bundles))
		free_exit(info);
	info->pids = (pid_t *)malloc(sizeof(pid_t) * (info->pipe_num + 1));
	if (!(info->pids))
	{
		ft_print_error(0, 0, strerror(errno));
		free_exit(info);
	}
	parsing(info->bundles, info);
	free_pid(info);
	free_str(info->bundles);
}

void	ft_readline(t_info *info)
{
	char	*input;

	while (1)
	{
		init_ctrl();
		init_reset(info);
		input = readline("\033[0;31mminishell$ \033[0;37m");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		else if (input[0] == '\0')
		{
			free(input);
		}
		else
		{
			add_history(input);
			minishell(input, info);
			free(input);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc == 1 && argv[0])
	{
		if (!init_env(&info, envp))
		{
			free_list(info.env_list);
			return (0);
		}
		g_exit_num = 0;
		ft_readline(&info);
		free_all(&info);
	}
	else
	{
		ft_print_error(0, 0, "too many parameters\n");
	}
	return (0);
}
