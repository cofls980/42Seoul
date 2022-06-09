#include "../includes/minishell.h"

int	redirection(char *name, t_info *info)
{
	int	fd;

	if (info->r_kind == INPUT_R)
		fd = open(name, O_RDONLY);
	else if (info->r_kind == OUTPUT_R)
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (info->r_kind == HERE_DOC_R)
	{
		fd = here_doc(name, info);
		if (g_exit_num == 1)
		{
			close(fd);
			info->here_doc = 1;
			return (0);
		}	
	}
	else if (info->r_kind == APPEND_R)
		fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd = -2;
	if (fd == -1)
	{
		ft_print_error(name, 0, strerror(errno));
		return (0);
	}
	if (fd != -2)
	{
		if (info->r_kind == INPUT_R || info->r_kind == HERE_DOC_R)
		{
			if (info->r_in_fd != -1)
				close(info->r_in_fd);
			info->r_in_fd = fd;
		}
		else
		{
			if (info->r_out_fd != -1)
				close(info->r_out_fd);
			info->r_out_fd = fd;
		}
	}
	return (1);
}

int	parse_redirect(char *bundle, char *name, t_info *info, t_word w_info)
{
	get_interpret_word(bundle, name, info, w_info);
	while (w_info.start < w_info.end)
		bundle[w_info.start++] = ' ';
	if (!redirection(name, info))
		return (0);
	return (1);
}

int	parsing_redirect(char *bundle, int start, t_info *info)
{
	char	*name;
	int		end;
	int		result;
	t_word	w_info;

	skip_space(bundle, &start);
	w_info.len = get_word_len(bundle, info, start, &end);
	if (w_info.len == 0 && info->r_kind != HERE_DOC_R) //error mssg에 추가
	{
		ft_print_error("\0", 0, strerror(2));
		return (-1);
	}
	name = (char *)malloc(sizeof(char) * (w_info.len + 1));
	if (!name)
	{
		ft_print_error(0, 0, strerror(errno));
		free_exit(info);
	}
	name[w_info.len] = '\0';
	w_info.end = end;
	w_info.start = start;
	result = parse_redirect(bundle, name, info, w_info);
	free(name);
	if (!result)
		return (-1);
	return (end);
}

int	solve_redirect(char *bundle, t_info *info) //오류일 때 처리
{
	int	i;
	int	quote;

	i = -1;
	quote = 0;
	while (bundle[++i])
	{
		info->r_kind = 0;
		check_quote(bundle[i], &quote);
		if ((bundle[i] == '>' || bundle[i] == '<') && !quote)
		{
			if (bundle[i] == '<')
				info->r_kind = 1;
			else
				info->r_kind = 2;
			if (bundle[i + 1] && bundle[i + 1] == bundle[i])
			{
				bundle[i] = ' ';
				bundle[i + 1] = ' ';
				info->r_kind += 2;
				i = parsing_redirect(bundle, i + 2, info) - 1;
			}
			else
			{
				bundle[i] = ' ';
				i = parsing_redirect(bundle, i + 1, info) - 1;
			}
		}
		if (i == -2)
			break ;
	}
	return (i);
}