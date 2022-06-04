#include "./includes/minishell.h"

void	ft_write(t_info *info, char *str)
{
	int		i;
	int		fd;
	char	c;
	
	i = 0;
	while (str[i])
	{
		if (info->redirect_out != -1)
			fd = info->redirect_out;
		else
			fd = info->output_file;
		c = str[i];
		write(fd, &c, 1);
		i++;
	}
}

void	free_str(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	init_str(char **strs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		strs[i] = 0;
		i++;
	}
}

void	error_message(char **strs, int flag) //리턴 -1하기
{
	if (flag == 0)
		printf("minishell: malloc error\n");
	else if (flag == 1)
		printf("minishell: syntax error\n");
	else if (flag == 2)
		printf("minishell: No such file or directory\n");
	else if (flag == 3)
		printf("minishell: Is a directory\n");
	else if (flag == 4)
		printf("minishell: pipe error\n");
	else if (flag == 5)
		printf("Command '' not found\n");
	else if (flag == 6)
		printf("minishell: command not found\n");
	free_str(strs);
}