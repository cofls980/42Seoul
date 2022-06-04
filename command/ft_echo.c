#include "../includes/minishell.h"
/*
	echo [-n옵션이 연속으로 여러번 들어가도됨] 123
	-n옵션이 -nnnnnnnnnnn이렇게 되도 됨.
*/
void	echo_print(char **command, int i, int option, t_info *info)
{
	while (command[i]) //문자열 출력
	{
		ft_write(info, command[i]);
		//printf("%s", command[i]);
		if (command[i + 1])
			ft_write(info, " ");
			//printf(" ");
		i++;
	}
	if (option == -1)
		ft_write(info, "\n");//printf("\n");
}

void	ft_echo(char **command, t_info *info)
{
	int		i;
	int		j;
	int		option;

	option = -1;
	i = 0;
	while (command[++i]) //-n발견
	{
		if (command[i][0] == '-' && command[i][1] == 'n')
		{
			j = 2;
			while (command[i][j])
			{
				if (command[i][j] != 'n')
					break;
				j++;
			}
			if (command[i][j])
				break;
		}
		else
			break;
		option = i;
	}
	echo_print(command, i, option, info);
}