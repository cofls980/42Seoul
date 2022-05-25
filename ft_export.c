#include "./includes/minishell.h"

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
			return (0);
		i++;
	}
	return (1);
}

void	ft_export(char **command, t_info *info) 
{
	t_list	*tmp;
	char	**envp_item;
	int		i;

	if (command[1] && command[1][0] == '-') //옵션이 들어올 경우
	{
		printf("minishell: export: -%c: do not need options\n", command[1][1]);
		return ;
	}
	tmp = info->list;
	i = 1;
	while (command[i])
	{
		if (have_equal(command[i])) // 유효한 =가 있는지
		{
			if(!is_key_valid(command[i]))//key 문자열 체크
				list_insert(&(tmp), new_item(ft_strdup(command[i]), 0, 0));
			else
				printf("minishell: export: %s: not a valid identifier\n", command[i]);
		}
		else
		{
			envp_item = split_equal(command[i]);
			//key 문자열 체크
			if (!is_key_valid(envp_item[0]))
			{
				if (envp_item)
					list_insert(&(tmp), new_item(envp_item[0], envp_item[1], 1));
			}
			else
				printf("minishell: export: %s: not a valid identifier\n", command[i]);
		}
		i++;
	}
	if (i == 1)// export 입력이 들어올 경우
	{
		while (tmp)
		{
			if (tmp->print)
				printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);//값에 큰따옴표가 있는 경우 맥에서 해결
			else
				printf("declare -x %s\n", tmp->key);
			tmp = tmp->next;
		}
	}
}