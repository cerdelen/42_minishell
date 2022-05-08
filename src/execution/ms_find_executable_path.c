#include "../../includes/minishell.h"

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

char	*check_if_exec_exists_and_x_rights(char **paths_w_cmd)
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

char	*find_executable_path_util(char	*cmd, char **env, t_ms_data *data, char **paths_with_cmd)
{
	char	*path;
	char	*out;

	path = check_if_exec_exists_and_x_rights(paths_with_cmd);
	out = free__path_arrays(path, paths_with_cmd);
	if (out == NULL)
	{
		print_error_message_builtin(cmd, "command not found", NULL);
		data->exit_codes = 127;
	}
	return (out);
}

char	*find_executable_path(char	*cmd, char **env, t_ms_data *data)
{
	char	*path;
	char	**paths_with_cmd;
	char	*out;

	if (cmd == NULL)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	path = get_path_from_env(env);
	paths_with_cmd = join_paths_with_cmd(path, cmd);
	if (paths_with_cmd)
		out = find_executable_path_util(cmd, env, data, paths_with_cmd);
	else
	{
		print_error_message_builtin(cmd, "command not found", NULL);
		data->exit_codes = 127;
		return (NULL);
	}
	return (out);
}
