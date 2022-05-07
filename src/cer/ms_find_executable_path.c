#include "../../includes/minishell.h"

char	*get_path_from_env(char **env)
{
	int		i;
	char	*out;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			out = ft_strjoin(env[i], "");
			return (out);
		}
		i++;
	}
	return (NULL);
}

char	**join_paths_with_cmd(char *paths, char *cmd)
{
	char	**paths_with_cmd;
	char	*tmp;
	int		i;

	if (paths == NULL)
		return (NULL);
	paths_with_cmd = ft_split(paths + 5, ':');
	i = 0;
	while (paths_with_cmd[i] != NULL)
	{
		tmp = paths_with_cmd[i];
		paths_with_cmd[i] = ft_tripple_strjoin(tmp, "/", cmd);
		free(tmp);
		i++;
	}
	free(paths);
	return (paths_with_cmd);
}

char	*check_if_exec_exists_and_x_rights(char **paths_w_cmd, char *cmd)
{
	int	i;
	int	check;

	i = 0;
	if (paths_w_cmd)
	{
		while (paths_w_cmd[i] != NULL)
		{
			check = access(paths_w_cmd[i], X_OK);
			if (check == 0)
				return (paths_w_cmd[i]);
			i++;
		}
	}
	return (NULL);
}

char	*free__path_arrays(char *path, char **arr)
{
	char	*out;
	int		i;

	i = 0;
	out = NULL;
	if (path != NULL)
		out = ft_strjoin(path, "");
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (out);
}

char	*find_executable_path(char	*cmd, char **env)
{
	char	*path;
	char	**paths_with_cmd;
	char	*out;

	if (cmd == NULL)
		return (NULL);
	printf("access == %d\n", access(cmd, X_OK));
	// return NULL;
	if (access(cmd, X_OK) == 0)
	{
		printf("HALLO\n");
		return (cmd);
	}
		printf("HALLO1\n");
	path = get_path_from_env(env);
		printf("HALLO2\n");
	paths_with_cmd = join_paths_with_cmd(path, cmd);
		printf("HALLO3\n");
	if (paths_with_cmd)
	{

	
		path = check_if_exec_exists_and_x_rights(paths_with_cmd, cmd);
			printf("HALLO4\n");
		out = free__path_arrays(path, paths_with_cmd);
			printf("HALLO5\n");
		if (out == NULL)
			printf("kiscer_ms: %s: command not found\n", cmd);
	}
	else
	{
		printf("kiscer_ms: %s: command not found\n", cmd);
		return (NULL);
	}
	return (out);
}
