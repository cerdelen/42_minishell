/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:58:17 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/08 13:07:14 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//ms_unset.c
int		ms_unset(t_ms_data *data);
int		ft_isalnum_underscore(int c);
int		ms_echo(char **cmd_flags);
int		ms_export(t_ms_data *data);
int		ms_env(char **cmd_flags, char **env);
int		ms_cd(char *pathname, char *home, t_ms_data *data);
int		ms_pwd(void);
int		ms_exit(t_ms_data *data);
#endif