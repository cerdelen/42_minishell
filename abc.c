#include "includes/minishell.h"


int main(int argc, char **argv, char **env)
{
	char *arr[2];

	arr[0]= "/bin/ls";
	arr[1]=	NULL;
	execve(arr[0], arr, env);
	return (0);
}
