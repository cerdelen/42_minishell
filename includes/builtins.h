/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:58:17 by kmilchev          #+#    #+#             */
/*   Updated: 2022/05/04 15:50:19 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//ms_unset.c
void	ms_unset(char **cmd_flags, char *env[]);
int		ft_isalnum_underscore(int c);
void	ms_echo(char **cmd);
char	**ms_export(char **cmd_flags, char *env[]);
#endif