#include "../includes/minishell.h"
/*
	환경 변수 추가 명령어
	1. 새로운 변수 추가(O)
	2. 기존에 있는 변수를 추가했을 시(O)
	3. 변수명=값 형식 지키기
		- 만약 변수명= 이렇게만 들어와도 통과되도록(O)
		- 변수명만 들어오면 추가없이 아무런 변화나 출력없음.(O)
		- 변수명 체크 -> 특수문자가 들어있거나 첫 문자가 숫자이면 에러
		- 변수명과 =과 값 사이에는 공백이 존재해서는 안된다.
		- 키 값이 숫자로 시작하거나 =으로 시작해서는 안된다.
	4. export abc=$var 이 형식이 적용되도록
	6. 옵션이 들어왔는지 아닌지 확인
	7. 그냥 export 했을 때 => export he 했던 것 들도 출력
*/
int	is_key_valid(char *str)//key 문자열 체크
{
	int	i;
	
	if (str[0] == '\0')
		return (1);
	if ('0' <= str[0] && str[0] <= '9')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] == '_' || ('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z') || ('0'<= str[i] && str[i] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

int	have_equal(char *str) // 유효한 =가 있는지
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && i != 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_declare(t_info *info, char *key, char *value)
{//값에 큰따옴표가 있는 경우 맥에서 해결
	ft_print(info, "declare -x ");
	ft_print(info, key);
	if (value)
	{
		ft_print(info, "=\"");
		ft_print(info, value);
		ft_print(info, "\"");
	}
	ft_print(info, "\n");
}

void	export_print(int i, t_info *info)
{
	t_list	*list;
	t_list	*set;

	list = info->env_list;
	set = NULL;
	if (i == 1)
	{
		while (list)
		{
			if (ft_strcmp(list->key, "_") != 0)
				list_insert_for_export(&(set), new_item(ft_strdup(list->key), ft_strdup(list->value), 1)); //알파벳 순으로 insert 되도록
			list = list->next;
		}
		list = set;
		while (list)
		{
			print_declare(info, list->key, list->value);
			list = list->next;
		}
		free_list(&set);
	}
}

int	ft_export(char **command, t_info *info)
{
	char	**envp_item;
	int		i;
	int		flag;
	int		status;

	if (command[1] && command[1][0] == '-')
	{
		command[1][2] = 0;
		ft_print_error(command[0], command[1], "invalid option");
		return (1);
	}
	i = 0;
	status = 0;
	while (command[++i])
	{
		flag = 0;
		envp_item = parsing_equal(command[i], &flag);
		if (envp_item && !is_key_valid(envp_item[0]))
		{
			if (have_equal(command[i]))
				list_insert(&(info->env_list), new_item(ft_strdup(envp_item[0]), ft_strdup(envp_item[1]), 1));
			else
				list_insert(&(info->env_list), new_item(ft_strdup(envp_item[0]), 0, 0));
		}
		else
		{
			status = 1;
			if (flag == 1)
			{
				status = -1000;
				break ;
			}
			ft_print_error(command[0], command[i], "not a valid identifier");
		}
		free_str(envp_item);
	}
	if (status != -1000)
		export_print(i, info);
	return (status);
}