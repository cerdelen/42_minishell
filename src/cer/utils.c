#include "minishell.h"

char	*ft_tripple_strjoin(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*out;

	temp = ft_strjoin(s1, s2);
	out = ft_strjoin(temp, s3);
	free(temp);
	return (out);
}
