#include "../includes/minishell.h"

void	execute(char **command, char **envp)
{
	char	*path;

	path = find_path(command[0], envp);
	if (execve(path, command, envp) == -1)
	{
		dup2(1, STDOUT_FILENO);
		printf("minishell: %s:command not found\n", command[0]);// 수정!!!!!!! 출력 위치가 이상해!!
		exit(EXIT_FAILURE);
	}
}

void	set_redirection(t_info *info)
{
	if (info->redirect_in != -1)
	{
		if (info->input_file != 0)
			close(info->input_file);
		dup2(info->redirect_in, STDIN_FILENO);
		close(info->redirect_in);
	}
	else
	{
		dup2(info->input_file, STDIN_FILENO);
		if (info->input_file != 0)
			close(info->input_file);
	}
	if (info->redirect_out != -1)
	{
		dup2(info->redirect_out, STDOUT_FILENO);
		close(info->redirect_out);
	}
	else
	{
		dup2(info->output_file, STDOUT_FILENO);
	}
}

pid_t	last_execute(char **command, t_info *info)//단순 실행
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (builtin_command(command, info))
			exit(0);
		else
		{
			set_redirection(info);
			execute(command, info->envp);
		}
	}
	return (pid);
}
//echo hello | grep h