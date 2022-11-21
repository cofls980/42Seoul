#include "../includes/minishell.h"

char	*malloc_name(t_info *info, int len)
{
	char	*name;

	name = (char *)malloc(sizeof(char) * (len + 1));
	if (!name)
	{
		ft_print_error(0, 0, strerror(errno));
		free_exit(info);
	}
	name[len] = '\0';
	return (name);
}

int	parsing_redirect(char *bundle, int start, t_info *info)
{
	char	*name;
	int		end;
	int		result;
	t_word	w_info;

	skip_space(bundle, &start);
	w_info.len = get_word_len(bundle, info, start, &end);
	if (w_info.len == 0 && info->r_kind != HERE_DOC_R)
	{
		ft_print_error("\0", 0, strerror(2));
		return (-1);
	}
	name = malloc_name(info, w_info.len);
	w_info.end = end;
	w_info.start = start;
	result = parse_redirect(bundle, name, info, w_info);
	free(name);
	if (!result)
		return (-1);
	return (end);
}

void	have_redirect(char *bundle, t_info *info, int *i)
{
	if (bundle[*i] == '<')
		info->r_kind = 1;
	else
		info->r_kind = 2;
	if (bundle[*i + 1] && bundle[*i + 1] == bundle[*i])
	{
		bundle[*i] = ' ';
		bundle[*i + 1] = ' ';
		info->r_kind += 2;
		*i = parsing_redirect(bundle, *i + 2, info) - 1;
	}
	else
	{
		bundle[*i] = ' ';
		*i = parsing_redirect(bundle, *i + 1, info) - 1;
	}
}

int	solve_redirect(char *bundle, t_info *info)
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
			have_redirect(bundle, info, &i);
		}
		if (i == -2)
			break ;
	}
	return (i);
}
