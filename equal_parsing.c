#include "./includes/minishell.h"

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
	return (-1);
}

char	*envp_parsing(char *str, int start, int len)
{
	int	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		return(0);
	}
	i = 0;
	while (i < len)
	{
		res[i] = str[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	check_key(char *str, int equal_idx) //key에 공백이 있는지 없는지 확인
{
	int	i;

	i = 0;
	while (i < equal_idx)
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

/*int	check_value(char *str, int equal_idx)
{
	int	i;

	i = equal_idx + 1;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}*/

int	is_check(char *str, int equal_idx)
{
	if (check_key(str, equal_idx))
		return (1);
	/*if (check_value(str, equal_idx))
		return (1);*/
	return (0);
}

char	**split_equal(char *str)
{
	char	**res;
	int equal_idx;
	int		i;

	res = (char **)malloc(sizeof(char *) * 3);
	if (!res)
		return (0);
	equal_idx = find_equal(str); //= 인덱스 번호
	if (equal_idx == -1)
		return (0);
	if (is_check(str, equal_idx))
	{
		printf("minishell: export: %s: not a valid identifier\n", str);
		return (0);
	}
	res[0] = envp_parsing(str, 0, equal_idx); //key malloc
	res[1] = envp_parsing(str, equal_idx + 1, ft_strlen(str + equal_idx + 1)); //value malloc
	res[2] = 0;
	return (res);
}
