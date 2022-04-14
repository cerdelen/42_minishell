#ifndef COMMANDS_AND_EXEC_H

# define COMMANDS_AND_EXEC_H

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3);
void	close_descriptors(int n_fds, ...);
char	**ft_free(char **array);
int		ft_validity_check(int n, char *error_message);
void	check_number_of_arguments(int n);
char	**get_paths(char *env[]);
// int		command_exec(t_ms_data *data);
char	*ft_strjoin_with_free(char *s1, char *s2);

#endif