/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_and_exec.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:38:03 by cerdelen          #+#    #+#             */
/*   Updated: 2022/05/08 15:38:04 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_AND_EXEC_H

# define COMMANDS_AND_EXEC_H

# define READS_ONLY 1
# define WRITES_ONLY 2
# define READS_AND_WRITES 3

typedef struct s_complex_command	t_cmd;
typedef struct s_ms_data			t_ms_data;

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3);
void	close_descriptors(int n_fds, ...);
char	**ft_free(char **array);
int		ft_validity_check(int n, char *error_message);
void	check_number_of_arguments(int n);
char	**get_paths(char *env[]);
char	*ft_strjoin_with_free(char *s1, char *s2);
int		print_error_message(char *error_arg1, char *error_arg2);
int		open_and_check_access(char *path, int access_flag,
			bool append, bool create);
char	*find_executable_path(char	*cmd, char **env, t_ms_data *data);
int		heredoc_prep(char *limiter, bool last, t_ms_data *data);
int		prep_input_fd(t_ms_data *data, int i, int in_fd);
int		prep_output_fd(t_ms_data *data, int i, int out_fd);
int		command_exec_loop(t_ms_data *data);
int		print_error_message_builtin(char *error_arg1, char *error_arg2,
			char *error_arg3);
int		print_error_message_export(char *error_arg1, char *error_arg2,
			char *error_arg3);
char	*get_path_from_env(char **env);
char	*free__path_arrays(char *path, char **arr);
int		cleanup_command(int cleanup_case, int in_fd, int out_fd);
char	*ms_find_home(char **env);
int		execute_exeption_command(t_ms_data *data, int in_fd, int out_fd,
			int *pipe_fd );
int		non_fork_exception(t_ms_data *data);
int		fork_for_exeption_command(t_ms_data *data, int in_fd, int out_fd);
char	*find_exeption_command(char *cmd);
int		child_proccess_managing_outfds(int out_fd, int *pipe_fd);
int		child_proccess_managing_infds(int in_fd, int *pipe_fd, t_ms_data *data);
void	child_process_prep(t_ms_data *data, int in_fd, int out_fd,
			int *pipe_fd);
int		fork_and_execute(t_ms_data *data, int in_fd, int out_fd);
int		command_exec_prep(t_ms_data *data, int i, int in_fd, int out_fd);
int		command_exec_loop(t_ms_data *data);
#endif