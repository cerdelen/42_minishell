/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:18:57 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/26 15:33:46 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalnum_underscore(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	else if (c == 95)
		return (1);
	else
		return (0);
}

int	validate_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum_underscore(str[i]))
		{
			printf("unset: '%s': not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	return (0);
}

void	update_array(char *var, char *env[])
{
	int	j;

	j = 0;
	while (env[j])
	{
		if (ft_strncmp(var, env[j], ft_strlen(var)) == 0)
		{
			free(env[j]);
			while (env[j + 1])
			{	
				env[j] = ft_strdup(env[j + 1]);
				j++;
			}
			env[j] = NULL;
			break ;
		}
		j++;
	}
}

void	unset(char **cmd_flags, char *env[])
{
	char	*var;
	int		i;
	int		j;
	int		err_res;

	i = 0;
	while (cmd_flags[i])
	{
		var = cmd_flags[i];
		err_res = validate_name(var);
		if (err_res)
		{
			i++;
			continue ;
		}
		update_array(var, env);
		i++;
	}
}

int main(int argc, char *argv[], char *env[])
{
	char **envv;
	envv = env_copy(env);
	char **cmd_flags;
	
	print_2d_array(envv);
	cmd_flags = malloc(21 * sizeof(char *));
	cmd_flags[0] = ft_strdup("TERM_PROGRAM");
	cmd_flags[1] = ft_strdup("TERM");
	cmd_flags[2] = ft_strdup("SHELL");
	cmd_flags[3] = ft_strdup("TMPDIR");
	cmd_flags[4] = ft_strdup("TERM_PROGRAM_VERSION");
	cmd_flags[5] = ft_strdup("OLDPWD");
	cmd_flags[6] = ft_strdup("ORIGINAL_XDG_CURRENT_DESKTOP");
	cmd_flags[7] = ft_strdup("USER");
	cmd_flags[8] = ft_strdup("COMMAND_MODE");
	cmd_flags[9] = ft_strdup("SSH_AUTH_SOCK");
	cmd_flags[10] = ft_strdup("__CF_USER_TEXT_ENCODING");
	cmd_flags[11] = ft_strdup("PATH");
	cmd_flags[12] = ft_strdup("LaunchInstanceID");
	cmd_flags[13] = ft_strdup("PWD");
	cmd_flags[14] = ft_strdup("LANG");
	cmd_flags[15] = ft_strdup("XPC_FLAGS");
	cmd_flags[16] = ft_strdup("XPC_SERVICE_NAME");
	cmd_flags[17] = ft_strdup("SHLVL");
	cmd_flags[18] = ft_strdup("HOME");
	cmd_flags[19] = ft_strdup("VSCODE_GIT_ASKPASS_MAIN");
	cmd_flags[20] = NULL;
	
	unset(cmd_flags, envv);
	print_2d_array(envv);
	free_2d_array(envv);
	free_2d_array(cmd_flags);
}
