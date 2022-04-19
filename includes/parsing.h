/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:46:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/19 12:57:24 by kmilchev         ###   ########.fr       */
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
	char	**input;
	char	**output;
	char	**out_append;
	char	**here_doc;
	char	**cmd_flags;
}	t_cmd;

typedef struct s_element_amounts
{
	int		n_red_in;
	int		n_red_out;
	int		n_app_out;
	int		n_here_doc;
	int		n_cmd_flags;
	int		idx_red_in;
	int		idx_red_out;
	int		idx_app_out;
	int		idx_here_doc;
	int		idx_cmd_flags;
}	t_n_el;

typedef struct s_env
{
	char	*var;
	char	*val;
}	t_env;

typedef struct s_norm
{
	char	**ptr;
	int		count;
	int		i;
	char	*str;
	char	*temp;
	bool	d_quotes_open;
	bool	s_quotes_open;
	int		idx;
}	t_data;

enum {
	NONE_OPEN = 0,
	S_OPEN_FIRST = 100,
	S_OPEN_SECOND = 101,
	S_OPEN_ONLY = 102,
	D_OPEN_FIRST = 200,
	D_OPEN_SECOND = 201,
	D_OPEN_ONLY = 202,
};

// parse.c 
int		parse(char **string, char *env[], t_cmd **cmds, int *cmd_amt);

//modified_split
char	**modified_split(char const *s, char c);

//parse_input
t_cmd	*fill_cmds_struct(char *string, int *command_amt);

//utils
int		count_chars(char *str, char c);
int		count_double_chars(char *str, char c);
int		count_strings(char **arr);

//free_utils
void	free_env_struct(t_env *envv, int i);
void	free_2d_array(char **arr);
void	free_struct_array(t_cmd *arr, int n_elements);
void	free_cmd_struct(t_cmd cmd);
void	free_cmd_struct_arr(t_cmd *cmd, int command_amt);

//print_utils
void	print_cmd_struct(t_cmd cmd);
void	print_env_struct(t_env *envv, int i);
void	print_2d_array(char **arr);
void	print_struct_array(t_cmd *arr, int n_elements);
void	print_cmd_struct_arr(t_cmd *arr, int command_amt);

//quotes_management
bool	all_quotes_are_closed(char *str);
bool	quotes_are_closed(char c);
void	reset_quotes(void);

//quotes_removal
int		double_quotes_open(int status);
int		single_quotes_open(int status);

//remove_spaces
void	remove_blank_spaces(char **string);
void	connect_double_angular_braces(char **string);
void	connect_singular_angular_braces(char **string);
void	remove_single_quotes(char **string, char rm, char keep);
void	remove_double_quotes(char **string, char rm, char keep);
void	remove_quotes(char **string);
void	disconnect_angular_braces(char **string);

//error_management
int		errors(char *string);
bool	double_pipe(char *string);
bool	multiple_redirection(char *string, char c);
bool	wrong_angular_braces(char *string);

//expand_env
t_env	*env_to_str(char **env, int j);
char	*expand(char *string, t_env *envv, int count);
char	*reassamble_string(char *string, char *add_str, int len_s1);
char	*remove_part_string(char *str, char*sub, int str_idx, int end_idx);
char	*find_match(char *string, t_env *arr, int len, int arr_size);

//expand_env_utils
bool	char_is_present(char c, char *string);
int		get_indices(char *string, int *start_idx, int *end_idx);

#endif