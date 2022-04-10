#include "../../includes/minishell.h"

int main(int argc, char **argv)
{
	int out;
	int i = 0;

	if (argv[1][0] == 'o')
		out = open("outfile", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (argv[1][0] == 'a')
		out = open("outfile", O_CREAT | O_WRONLY | O_APPEND, 0777);

	while (i < 10)
	{
		i++;
		write(out, "ABCDEFG\n", 8);
	}
}
