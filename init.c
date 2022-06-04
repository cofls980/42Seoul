#include "./includes/minishell.h"

void	init(t_info *info, char **envp) //수정
{
	char	*value;
	char	**envp_item;
	int		i;

	value = getenv("HOME");
	if (value)
		info->home = value;
	else
	{
		printf("ERROR\n");
		return ;
	}
	info->envp = envp;
	info->list = NULL;
	i = 0;
	while (envp[i])
	{
		envp_item = split_equal(envp[i]);
		/*if (!envp_item)//--->정해야함.
			return ;*/
		list_insert(&(info->list), new_item(envp_item[0], envp_item[1], 1));
		i++;
	}
	info->pipe_count = 0;
	info->have_pipe = 0;
	info->redirect = 0;
	info->input_file = 0;
	info->output_file = 1;
}