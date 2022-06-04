/*
	pwd 뒤에 어떤 파라미터가 오던지 상관없음
	대신 옵션이 들어오는 순간 오류 출력
	옵션은 따옴표에 상관없이 -[c]가 오면 인식
*/
#include "../includes/minishell.h"

void	ft_pwd(char **cmd, t_info *info)
{
	int	i;

	if (cmd[1])
	{
		i = 0;
		if (cmd[1][i] == '-')
		{
			cmd[1][i + 2] = 0;
			ft_write(info, "minishell: pwd: ");
			ft_write(info, cmd[1]);
			ft_write(info, ": do not need options\n");
			//printf("minishell: pwd: %c%c: do not need options\n", cmd[1][i], cmd[1][i + 1]); //dup2(1, STDOUT);
			return;
		}
	}
	ft_write(info, list_find(&(info->list), "PWD"));
	ft_write(info, "\n");
	//printf("%s\n", list_find(&(info->list), "PWD"));//PWD찾기
}