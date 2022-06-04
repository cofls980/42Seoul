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
	return (-1);
}

char	*envp_parsing(char *str, int start, int len)
{
	int	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		error_message(0, 0);
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
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**split_equal(char *str)// key, value 분리
{
	char	**res;
	int equal_idx;

	res = (char **)malloc(sizeof(char *) * 3);
	if (!res)
	{
		error_message(0, 0);
		return (0);
	}
	init_str(res, 3);
	equal_idx = find_equal(str); //= 인덱스 번호
	if (check_key(str, equal_idx))
	{
		printf("minishell: export: %s: not a valid identifier\n", str);
		return (0);
	}
	res[0] = envp_parsing(str, 0, equal_idx); //key malloc
	if (equal_idx != -1)
		res[1] = envp_parsing(str, equal_idx + 1, ft_strlen(str + equal_idx + 1)); //value malloc
	return (res);
}
