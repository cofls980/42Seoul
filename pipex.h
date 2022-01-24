#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./Libft/libft.h"

typedef struct		s_fdlist
{
    int closefd;
    int stdinfd;
    int stdoutfd;
}					t_fdlist;

int     main(int argc, char *argv[], char *envp[]);

#endif
