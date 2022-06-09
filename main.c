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
		if (info->pids[i] == -2)
		{
			i++;
			e_num = -1;
			continue ;
		}
		waitpid(info->pids[i++], &status, 0);
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
		info->r_in_fd = -1;
		info->r_out_fd = -1;
		info->r_kind = 0;
		info->here_doc = 0;
		parts = 0;
		info->pids[i] = -2;
		if (solve_redirect(bundles[i], info) != -2)
		{
			parts = split_words(bundles[i], info);
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
		g_exit_num = 258;//check
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
		if (info->exit == 1)
			break ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc == 1 && argv[0])
	{
		if (!init_env(&info, envp))
		{
			free_list(&(info.env_list));
			return (0);
		}
		ft_readline(&info);
		free_all(&info);
	}
	else
	{
		ft_print_error(0, 0, "too many parameters\n");
	}
	//leaks
	system("leaks minishell > leaks_result; cat leaks_result | grep leaked; rm -rf leaks_result");
	return (0);
}