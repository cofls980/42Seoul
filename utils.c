#include "pipex.h"

void	init_flist(char **argv, char **envp, t_fdlist *flist)
{
	flist->command1 = ft_split(argv[2], ' ');
	flist->command2 = ft_split(argv[3], ' ');
	flist->path1 = find_path((flist->command1)[0], envp);
	flist->path2 = find_path((flist->command2)[0], envp);
}

void	free_path(char **en_paths)
{
	int i;

	i = 0;
	if (en_paths)
	{
		while (en_paths[i])
		{
			free(en_paths[i]);
			en_paths[i] = NULL;
			i++;
		}
		free(en_paths);
		en_paths = NULL;
	}
}

void    free_all(t_fdlist *flist)
{
	free(flist->path1);
	free(flist->path2);
	flist->path1 = NULL;
	flist->path2 = NULL;
	free_path(flist->command1);
	free_path(flist->command2);
}

void	ft_error(char *mssg, t_fdlist *flist)
{
    if (flist != 0)
    {
        free_all(flist);
    } 
	perror(mssg);
	exit(1);
}

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