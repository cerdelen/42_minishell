int	str_only_numerical(char *str)
{
	while (*str != 0)
		if (*str < '0' || *str++ > '9')
			return (1);
	return (0);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	printf("%d\n", str_only_numerical(argv[1]));
}