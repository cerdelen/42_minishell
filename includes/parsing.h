/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:46:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/10 15:28:14 by kmilchev         ###   ########.fr       */
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
	char	**reddir_in;
	char	**reddir_out;
	char	**reddir_out_app;
	char	**here_doc;
	char	*cmd;
	char	*flags;
} t_full_pipe;

typedef struct s_remove_substring
{
	int i;
	int j;
	int len;
	int start_index;
	int finish_index;
} t_r_s;

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
int		count_chars(char *str, char c);
int		count_double_chars(char *str, char c);

//redirection
char	**get_single_redirections(char **string, char symbol, t_r_s *vars);
char	**get_double_redirections(char **string, char symbol, t_r_s *vars);
char	*find_single_redirection(char *string, char symbol, t_r_s *vars);
char	*find_double_redirection(char *string, char symbol, t_r_s *vars);
char	*trim_string(char *str, char*sub, t_r_s *vars);
#endif