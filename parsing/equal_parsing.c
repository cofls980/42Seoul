#include "../includes/minishell.h"

int	find_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

char	*envp_parsing(char *str, int start, int len)
{
	int	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		ft_print_error(0, 0, strerror(errno));
		return(0);
	}
	i = 0;
	while (i < len)
	{
		res[i] = str[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	check_key(char *str, int equal_idx) //key에 공백이 있는지 없는지 확인
{
	int	i;

	i = 0;
	while (i < equal_idx)
	{
		if (is_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	**split_equal(char *str, int *flag)
{
	char	**res;
	int		equal_idx;

	equal_idx = find_equal(str);
	if (check_key(str, equal_idx))
		return (0);
	res = (char **)malloc(sizeof(char *) * 3);
	if (!res)
	{
		ft_print_error(0, 0, strerror(errno));
		*flag = 1;
		return (0);
	}
	init_str(res, 3);
	res[0] = envp_parsing(str, 0, equal_idx);
	if (res[0] && ft_strlen(str + equal_idx) != 0)
	{
		res[1] = envp_parsing(str, equal_idx + 1, ft_strlen(str + equal_idx + 1)); //value malloc
		if (!res[1])
		{
			free_str(res);
			*flag = 1;
			return (0);
		}
	}
	return (res);
}
