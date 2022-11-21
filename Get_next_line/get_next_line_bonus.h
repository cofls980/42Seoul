#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

int		get_next_line(int fd, char **line);
int		is_newline(char *backup);
int		have_newline(char **backup, char **line, int i);
int		until_end(char **backup, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *dst, const char *src);

#endif
