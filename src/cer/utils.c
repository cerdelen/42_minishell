#include "../../includes/minishell.h"

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*out;

	temp = ft_strjoin(s1, s2);
	out = ft_strjoin(temp, s3);
	free(temp);
	return (out);
}

char	*ft_strjoin_with_free(char *s1, char *s2)
{
	char	*out;

	out = ft_strjoin(s1, s2);
	free(s1);
	return (out);
}