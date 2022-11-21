#include "../includes/minishell.h"

int	count_word(char *str)
{
	int	i;
	int	cnt;
	int	word;
	int	quote;

	i = 0;
	cnt = 0;
	word = 0;
	quote = 0;
	while (str[i])
	{
		check_quote(str[i], &quote);
		if (!is_space(str[i]) && !word)
		{
			cnt++;
			word = 1;
		}
		if (is_space(str[i]) && word && !quote)
			word = 0;
		i++;
	}
	return (cnt);
}

int	find_word(char *str, int *start)
{
	int	i;
	int	word;
	int	quote;

	skip_space(str, start);
	i = *start;
	word = 0;
	quote = 0;
	while (str[i])
	{
		check_quote(str[i], &quote);
		if (!is_space(str[i]) && !word)
			word = 1;
		if (is_space(str[i]) && word && !quote)
			break ;
		i++;
	}
	return (i);
}

char	**split_words(char *bundle, t_info *info, t_word w_info, int i)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (w_info.len + 1));
	if (!res)
	{
		ft_print_error(0, 0, strerror(errno));
		close_iofd(info);
		free_exit(info);
	}
	init_str(res, w_info.len + 1);
	while (i < w_info.len)
	{
		w_info.end = find_word(bundle, &(w_info.start));
		res[i] = (char *)malloc(sizeof(char) * (w_info.end - w_info.start + 1));
		if (!res[i])
		{
			ft_print_error(0, 0, strerror(errno));
			close_iofd(info);
			free_str(res);
			free_exit(info);
		}
		fill_word(bundle, res[i++], w_info.start, w_info.end);
		w_info.start = w_info.end;
	}
	return (res);
}

char	**parsing_words(char *bundle, t_info *info)
{
	t_word	w_info;
	int		i;

	w_info.len = count_word(bundle);
	if (w_info.len == 0)
		return (0);
	i = 0;
	w_info.start = 0;
	return (split_words(bundle, info, w_info, i));
}
