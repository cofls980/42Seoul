#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		one;
	int		two;
	int		i;

	if (!s1 && !s2)
		return (0);
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (one + two + 1))))
		return (0);
	i = 0;
	while (i < one)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < two)
	{
		str[one + i] = s2[i];
		i++;
	}
	str[one + two] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		else if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


char   *find_path(char *command, char **envp)
{
   char   **en_paths;
   char   *path1;
   char   *path2;
   int   i;

   if (!envp && !command)
      return (0);
   i = 0;
   while (ft_strncmp(envp[i], "PATH=", 5) != 0)
      i++;
   en_paths = ft_split(envp[i] + 5, ':');
   i = 0;
   while (en_paths[i])
   {
      path1 = ft_strjoin(en_paths[i], "/");
      path2 = ft_strjoin(path1, command);
      free(path1);
      if (access(path2, F_OK) == 0)
      {
         free_path(en_paths);
         return (path2);
      }
      i++;
      free(path2);
   }
   free_path(en_paths);
   return (ft_strjoin("", command));
}