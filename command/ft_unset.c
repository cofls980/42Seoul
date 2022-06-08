#include "../includes/minishell.h"
/*
	변수명에 _를 제외한 특수 문자가 들어가면 에러 처리
	그리고 처음에 숫자가 오면 안된다.
	minishell: unset: '': not a valid identifier
*/
int	is_valid(char *str) // 환경 변수명으로 사용될 문자열이 올바른 구성으로 되어있는지 확인
{
	int	i;

	if (str[0] == '\0')
		return (1);
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

int	ft_unset(char **cmd, t_info *info)
{
	int i;
	int	status;

	if (cmd[1] && cmd[1][0] == '-') // 옵션이 있는지 없는지 확인
	{
		cmd[1][2] = 0;
		ft_print_error(cmd[0], cmd[1], "invalid option");
		return (2);//check
	}
	i = 1;
	status = 0;
	while (cmd[i])
	{
		if (is_valid(cmd[i]))
		{
			ft_print_error(cmd[0], cmd[i], "not a valid identifier");
			status = 1;
		}
		else
		{
			list_remove(&(info->env_list), cmd[i]);
			list_remove(&(info->export_list), cmd[i]);
			list_remove(&(info->user_list), cmd[i]);
		}
		i++;
	}
	return (status);
}