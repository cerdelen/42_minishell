/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:46:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/17 20:55:01 by kmilchev         ###   ########.fr       */
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
	// char	**envv;
	char	**cmd_flags; //NULL
} t_full_pipe;

typedef struct s_element_amounts
{
	int n_red_in;
	int n_red_out;
	int n_red_out_app;
	int n_here_doc;
	int n_cmd_flags;
	int idx_red_in;
	int idx_red_out;
	int idx_red_out_app;
	int idx_here_doc;
	int idx_cmd_flags;
}t_n_el;
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

enum {
	NONE_OPEN = 0,
	S_OPEN_FIRST = 100,
	S_OPEN_SECOND = 101,
	// S_CLOSED = 102,
	S_OPEN_ONLY = 103,
	D_OPEN_FIRST = 200,
	D_OPEN_SECOND = 201,
	// D_CLOSED = 202,
	D_OPEN_ONLY = 203,
	
};

//modified_split
char	**modified_split(char const *s, char c);

//parse_input
t_full_pipe fill_cmd(char *arr);

//utils
int		count_chars(char *str, char c);
int		count_double_chars(char *str, char c);
int		count_strings(char **arr);

//free_utils
void	free_env_struct(t_env *envv, int i);
void	free_2d_array(char **arr);
void	free_struct_array(t_full_pipe *arr, int n_elements);
void	free_cmd_struct(t_full_pipe cmd);
void	free_cmd_struct_arr(t_full_pipe *cmd, int command_amt);

//print_utils
void	print_cmd_struct(t_full_pipe cmd);
void	print_env_struct(t_env *envv, int i);
void	print_2d_array(char **arr);
void	print_struct_array(t_full_pipe *arr, int n_elements);
void	print_cmd_struct_arr(t_full_pipe *arr, int command_amt);

//quotes_management
bool	all_quotes_are_closed(char *str);
bool	quotes_are_closed(char c);
int		double_quotes_open(int status);
int		single_quotes_open(int status);

//redirection
char	**get_single_redirections(char **string, char symbol, t_r_s *vars);
char	**get_double_redirections(char **string, char symbol, t_r_s *vars);
char	*find_single_redirection(char *string, char symbol, t_r_s *vars);
char	*find_double_redirection(char *string, char symbol, t_r_s *vars);
char	*trim_string(char *str, char*sub, t_r_s *vars);

//remove_spaces
void	remove_blank_spaces(char **string);
void	connect_double_angular_braces(char **string);
void	connect_singular_angular_braces(char **string);
void	remove_single_quotes(char **string, char rm, char keep);
void	remove_double_quotes(char **string, char rm, char keep);

//TEST
char *remove_blank_spaces2(char *string);

//error_management
int		errors(char *string);
bool	double_pipe(char *string);
bool	multiple_redirection(char *string, char c);
bool	wrong_angular_braces(char *string);

//expand_env
t_env	*env_to_str(char **env, int j);
int		get_indices(char *string, int *start_idx, int *end_idx);
char	*expand(char *string, t_env *envv, int count);
char	*reassamble_string(char *string,  char *add_str, int len_s1);
char	*remove_part_string(char *str, char*sub, int start_index, int finish_index);
char	*find_match(char *string, t_env *arr, int len, int arr_size);
bool	char_is_present(char c, char *string);







int parse(int argc, char *argv[], char* env[]);
#endif