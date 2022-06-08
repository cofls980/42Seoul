#include "./includes/minishell.h"

void	free_pid(t_info *info)
{
	int	i;
	int	status;

	i = 0;
	while (i < info->have_pipe)
	{
		if (info->pids[i] == -2)
		{
			i++;
			continue ;
		}
		waitpid(info->pids[i++], 0, 0);
	}
	//마지막 명령어만 status 가져오기
	if (info->pids[i] != -2)
	{
		waitpid(info->pids[i], &status, 0);
		g_exit_num = (status & 0xff00) >> 8;
	}
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
		info->r_in_fd = -1;
		info->r_out_fd = -1;
		info->r_kind = 0;
		parts = 0;
		if (solve_redirect(bundles[i], info) != -2)
		{
			parts = split_words(bundles[i]);
			if (parts && interpret_word(parts, info))
				info->pids[i] = command(parts, info);
			else
				g_exit_num = 1;
		}
		else
			g_exit_num = 1;
		info->pipe_num--;
		free_str(parts);
	}
}

void	minishell(char *input, t_info *info)
{
	if (check_syntax(input, info))
	{
		ft_print_error(0, 0, "syntax error near unexpected token");
		g_exit_num = 2;//check
		return ;
	}
	info->bundles = pipe_parsing(input, info);
	if (!(info->bundles))
	{
		g_exit_num = 1;
		return ;
	}
	info->pids = (pid_t *)malloc(sizeof(pid_t) * (info->pipe_num + 1));
	if (!(info->pids))
	{
		ft_print_error(0, 0, strerror(errno));
		free_str(info->bundles);
		g_exit_num = 1;
		return ;
	}
	parsing(info->bundles, info);
	free_pid(info);
	free_str(info->bundles);
}

void	ft_readline(t_info *info)
{
	char	*input;

	init_ctrl();
	while (1)
	{
		init_reset(info);
		input = readline("\033[0;31mminishell$ \033[0;37m");
		if (!input)
		{
			printf("\n");
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
			return (0);
		init(&info);
		ft_readline(&info);
		free_all(&info);
	}
	else
	{
		ft_print_error(0, 0, "too many parameters\n");
	}
	return (0);
}