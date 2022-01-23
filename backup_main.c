/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaekim <chaekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:05:59 by chaekim           #+#    #+#             */
/*   Updated: 2022/01/21 18:01:12 by chaekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print(char *str)
{
	int		i;
	char	ch;

	i = 0;
	while (*(str + i))
	{
		ch = *(str + i);
		write(1, &ch, 1);
		i++;
	}
}

int	str_len(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	dup2_stdin_stdout(int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
		{
			close(in);
			perror("dup2");
			exit(1);
		}
		close(in);
		if (dup2(out, STDOUT_FILENO) == -1)
		{
			close(out);
			perror("dup2");
			exit(1);
		}
		close(out);
}

int	main(int argc, char *argv[])//, char *envp[])
{
	char	*path;
	char	**command;
	int		fd_open_file;
	int		fd_output;
	pid_t	pid;
	int		fd[2];

	//printf("%s\n", envp[1]);
	if (argc != 5)
	{
		perror("parameters");
		exit(1);
		//print("wrong parameters\n");
		//return (0);
	}
	if (pipe(fd) == -1) //자식 프로세스가 부모가 보낸 데이터를 읽을 때까지 기다리다 파이프에 데이터가 있으면 이를 읽어서 처리한다.
	{
		perror("pipe");
		exit(1);
		//print("pipe error\n");
		//return (0);
	}
	pid = fork();
	if (pid > 0) //부모 프로세서
	{
		command = split(argv[2]);
		if (!command)
		{
			perror("command");
			exit(1);
		}
		path = find_path(command[0]);
		printf("path: %s\n", path);
		if (!path)
		{
			perror("path");
			exit(1);
		}
		// < redirection
		fd_open_file = open(argv[1], O_RDONLY);
		if (fd_open_file == -1)
		{
			perror("open");
			exit(1);
		}
		close(fd[0]);
		//dup2_stdin_stdout(fd_open_file, fd[1]);
		//입력
		if (dup2(fd_open_file, STDIN_FILENO) == -1)
		{
			close(fd_open_file);
			perror("dup2");
			exit(1);
			//print("dup2 error\n");
			//close(fd_open_file);
			//return (0);
		}
		close(fd_open_file);
		//출력
		//부모에서 fd[1]을 사용하여 파이프에 데이터를 보낸다.
		if (dup2(fd[1], STDOUT_FILENO) == -1)
		{
			close(fd[1]);
			perror("dup2");
			exit(1);
		}
		close(fd[1]);
		if (execve(path, command, NULL) == -1) //커맨드 경로, 파일 인자의 포인터, 환경변수의 포인터
		{
			perror("parent execve");
			exit(1);
			//print("exec fail\n");
			//return (0);
		}
		//만약에 exec가 정상적으로 실행된다면 새로운 프로세스가 되므로 아래 코드들은 실행되지 않는다.
		//waitpid의 정상 반환은 pid와 같은 값
		if (waitpid(pid, NULL, WNOHANG) == -1) //pid의 자식 프로세프가 끝날 때까지 기다림.
		{
			perror("waitpid");
			exit(1);
			//print("wait fail");
			//exit(-1);
		}
	}
	else if (pid == 0) //자식 프로세서
	{
		command = split(argv[3]);
		if (!command)
		{
			perror("command");
			exit(1);
		}
		path = find_path(command[0]);
		if (!path)
		{
			perror("command");
			exit(1);
		}
		//> redirection
		fd_output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);//0644?
		if (fd_output == -1)
		{
			perror("open");
			exit(128);
		}
		close(fd[1]);
		//출력
		// 부모가 보낸 것을 가져다가 사용
		//dup2_stdin_stdout(fd[0], fd_output);
		if (dup2(fd_output, STDOUT_FILENO) == -1)
		{
			close(fd_output);
			perror("dup2");
			exit(1);
		}
		close(fd_output);
		//입력
		if (dup2(fd[0], STDIN_FILENO) == -1)
		{
			close(fd[0]);
			perror("dup2");
			exit(1);
		}
		close(fd[0]);
		if (execve(path, command, NULL) == -1)
		{
			perror("child execve");
			exit(1);
		}
	}
	else
	{
		perror("fork");
		exit(1);
	}
	return (0);
}
