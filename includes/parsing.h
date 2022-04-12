/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:46:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/12 18:37:24 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_complex_command
{
	char	**reddir_in; //NULL
	char	**reddir_out; //NULL
	char	**reddir_out_app; //NULL
	char	**here_doc; //NULL
	char	**envv;
	// char	*cmd;
	// char	**flags; //NULL
	char	**cmd_flags; //NULL
} t_full_pipe;

typedef struct s_remove_substring
{
	int i;
	int j;
	int len;
	int start_index;
	int finish_index;
} t_r_s;

typedef struct s_env
{
	char *var;
	char *val;
} t_env;

//modified_split
char	**modified_split(char const *s, char c);

//parse_input
bool	quotes_are_closed(char *str);
bool	quotes_are_closed_no_loop(char c);
bool	double_pipe(char *string);
bool	multiple_redirection(char *string, char c);
char	*find_single_redirection(char *string, char symbol, t_r_s *vars);
char	*trim_string(char *str, char*sub, t_r_s *vars);

//utils
void	print_struct_array(t_full_pipe *arr, int n_elements);
void	print_2d_array(char **arr);
void	free_2d_array(char **arr);
void	free_struct_array(t_full_pipe *arr, int n_elements);
void	print_env_struct(t_env *envv, int i);
void	free_env_struct(t_env *envv, int i);
int		count_chars(char *str, char c);
int		count_double_chars(char *str, char c);

//redirection
char	**get_single_redirections(char **string, char symbol, t_r_s *vars);
char	**get_double_redirections(char **string, char symbol, t_r_s *vars);
char	*find_single_redirection(char *string, char symbol, t_r_s *vars);
char	*find_double_redirection(char *string, char symbol, t_r_s *vars);
char	*trim_string(char *str, char*sub, t_r_s *vars);

//remove_spaces
void	remove_blank_spaces(char **string);
//TEST
char *remove_blank_spaces2(char *string);

//error_management
int		errors(char *string);

//expand_env
void expand_env(char **string, char **env);
#endif