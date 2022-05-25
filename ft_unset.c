#include "./includes/minishell.h"
/*
	변수명에 _를 제외한 특수 문자가 들어가면 에러 처리
	그리고 처음에 숫자가 오면 안된다.
	minishell: unset: '': not a valid identifier
*/
int	is_valid(char *str) // 환경 변수명으로 사용될 문자열이 올바른 구성으로 되어있는지 확인
{
	int	i;

	if ('0' <= str[0] && str[0] <= '9')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z') || str[i] == '_' || ('0'<= str[i] && str[i] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

void	ft_unset(char **cmd, t_info *info)
{
	int i;

	if (cmd[1] && cmd[1][0] == '-') // 옵션이 있는지 없는지 확인
	{
		printf("minishell: unset: -%c: do not need options\n", cmd[1][1]);
		return ;
	}
	i = 1;
	while (cmd[i])
	{
		if (is_valid(cmd[i]))
		{
			printf("minishell: unset: %s: not a valid identifier\n", cmd[i]);
		}
		else
		{
			//find and remove
			list_remove(&(info->list), cmd[i]);
		}
		i++;
	}
}