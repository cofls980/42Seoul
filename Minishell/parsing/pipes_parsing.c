#include "../includes/minishell.h"

int	find_string(char *input, int start)
{
	int	i;
	int	quote;

	i = start;
	quote = 0;
	while (input[i])
	{
		check_quote(input[i], &quote);
		if (input[i] == '|' && !quote)
			break ;
		i++;
	}
	return (i);
}

char	**split_with_pipe(char *input, char **res, t_info *info)
{
	int		i;
	int		start;
	int		end;

	i = -1;
	start = 0;
	while (++i <= info->pipe_num)
	{
		skip_space(input, &start);
		end = find_string(input, start);
		res[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!res[i])
		{
			ft_print_error(0, 0, strerror(errno));
			free_exit(info);
		}
		fill_word(input, res[i], start, end);
		start = end + 1;
	}
	return (res);
}

char	**pipe_parsing(char *input, t_info *info)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (info->pipe_num + 2));
	if (!res)
	{
		ft_print_error(0, 0, strerror(errno));
		free_exit(info);
	}
	init_str(res, info->pipe_num + 2);
	return (split_with_pipe(input, res, info));
}
