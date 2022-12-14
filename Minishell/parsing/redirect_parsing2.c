#include "../includes/minishell.h"

int	redirect_check(char *name, int fd, t_info *info)
{
	if (fd == -1)
	{
		ft_print_error(name, 0, strerror(errno));
		close_iofd(info);
		free_exit(info);
	}
	if (fd != -2)
	{
		if (info->r_kind == INPUT_R || info->r_kind == HERE_DOC_R)
		{
			if (info->r_in_fd != -1)
				close_fd(info->r_in_fd, info);
			info->r_in_fd = fd;
		}
		else
		{
			if (info->r_out_fd != -1)
				close_fd(info->r_out_fd, info);
			info->r_out_fd = fd;
		}
	}
	return (1);
}

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
			close_fd(fd, info);
			info->here_doc = 1;
			return (0);
		}	
	}
	else if (info->r_kind == APPEND_R)
		fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd = -2;
	return (redirect_check(name, fd, info));
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
