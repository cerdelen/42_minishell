/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:58:17 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/04 16:54:52 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//ms_unset.c
int		ms_unset(t_ms_data *data);
int		ft_isalnum_underscore(int c);
int		ms_echo(char **cmd);
int		ms_export(t_ms_data *data);
int		ms_env(char **cmd, char **env);
int		ms_cd(char *pathname, char *home);
#endif