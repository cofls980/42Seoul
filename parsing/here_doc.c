#include "../includes/minishell.h"

int here_doc(char *limit, t_info *info)
{
	char	*input;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		error_message(0, 4);
		return (-1);
	}
	info->here_doc = 1;
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			printf("minishell: warning: here-document at line 299 delimited by end-of-file\n");
			break ;
		}
		else if (input[0] == '\0')
		{
			if (ft_strcmp(limit, input) == 0)
			{
				free(input);
				break ;
			}
			free(input);
		}
		else
		{
			if (ft_strcmp(limit, input) == 0)
			{
				free(input);
				break ;
			}
			write(fd[1], input, ft_strlen(input));
			write(fd[1], "\n", 1);
			free(input);
		}
	}
	close(fd[1]);
	return (fd[0]);
}