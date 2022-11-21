#include "../includes/pipex.h"

void	init_info(int argc, char **argv, char **envp, t_info *info)
{
	info->argv = argv;
	info->envp = envp;
	info->argc = argc;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		iofd[2];

	if (argc != 5)
		display_error("try again\n");
	init_info(argc, argv, envp, &info);
	iofd[0] = open_file(argv[1], 0);
	iofd[1] = open_file(argv[argc - 1], 1);
	duplicate(iofd[0], STDIN_FILENO);
	pipex(info, iofd[1], info.argc - 3, 2);
	return (0);
}