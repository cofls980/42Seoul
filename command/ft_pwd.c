/*
	pwd 뒤에 어떤 파라미터가 오던지 상관없음
	대신 옵션이 들어오는 순간 오류 출력
	옵션은 따옴표에 상관없이 -[c]가 오면 인식
*/
#include "../includes/minishell.h"

int	ft_pwd(char **cmd, t_info *info)
{
	int		i;
	char	*path;

	if (cmd[1])
	{
		i = 0;
		if (cmd[1][i] == '-')
		{
			cmd[1][i + 2] = 0;
			ft_print_error(cmd[0], cmd[1], "invalid option");
			return (1);
		}
	}
	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_print_error(cmd[0],cmd[1],strerror(errno));
		return (1);
	}
	ft_print(info, path);
	ft_print(info, "\n");
	free(path);
	return (0);
}