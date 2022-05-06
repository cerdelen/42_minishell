#ifndef COMMANDS_AND_EXEC_H

# define COMMANDS_AND_EXEC_H

# define READS_ONLY 1
# define WRITES_ONLY 2
# define READS_AND_WRITES 3

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
char	*find_executable_path(char	*cmd, char **env);
int		heredoc_prep(char *limiter, bool fake);
int		prep_input_fd(t_ms_data *data, int i, int in_fd);
int		prep_output_fd(t_ms_data *data, int i, int out_fd);
int		command_exec_loop(t_ms_data *data);
void	ms_exit(t_ms_data *data);
int		print_error_message_builtin(char *error_arg1, char *error_arg2,
			char *error_arg3);
int		print_error_message_export(char *error_arg1, char *error_arg2, char *error_arg3);


#endif