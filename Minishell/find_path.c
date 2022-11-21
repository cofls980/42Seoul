#include "./includes/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

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

int	is_access(char *path, char **en_paths)
{
	if (open(path, O_RDONLY) != -1)
	{
		free_str(en_paths);
		return (0);
	}
	return (1);
}

char	*find_path(char *command, char **envp)
{
	char	**en_paths;
	char	*path1;
	char	*path2;
	int		i;

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
		if (is_access(path2, en_paths) == 0)
			return (path2);
		free(path2);
		i++;
	}
	free_str(en_paths);
	return (ft_strjoin("", command));
}
