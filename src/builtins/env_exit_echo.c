/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:00:30 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/27 22:42:20 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(char **cmd, char **env)
{
	if (cmd[1])
		printf("env: the command does not accept arguments\n");
	else
		print_2d_array(env);
}

void	ft_exit(char **cmd)
{
	if (cmd[1])
		printf("exit: the command does not accept arguments\n");
	printf("exit\n");
	////////////////TBD
}

bool	flag_is_present(char **cmd, int *i)
{
	int		j;
	bool	new_line;

	j = 1;
	new_line = false;
	if (cmd[*i][0] == '-' && cmd[*i][1] == 'n')
	{
		while (cmd[*i][j])
		{
			if (cmd[*i][j] != 'n')
			{
				new_line = true;
				break ;
			}
			j++;
		}
		(*i)++;
	}
	return (new_line);
}

bool	every_char_is(char c, char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != c)
			return (false);
		i++;
	}
	return (true);
}

void	ft_echo(char **cmd)
{
	int		i;
	int		j;
	bool	put_out;
	bool	new_line;

	i = 1;
	put_out = true;
	new_line = false;
	new_line = flag_is_present(cmd, &i);
	while (cmd[i])
	{
		if (cmd[i][0] == '-' && every_char_is('n', cmd[i]))
		{
			i++;
			continue ;
		}
		printf("%s", cmd[i]);
		if (cmd[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (new_line)
		printf("\n");
}

// int main(int a, char**b, char *env[])
// {
// 	char *arr[20] = {"echo", "-n", "-nnnnna", "more", NULL};
// 	ft_echo(arr);
// }