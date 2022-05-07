#include "includes/minishell.h"


int main(int argc, char **argv, char **env)
{
	char *arr[2];

	arr[0]= "./minishell";
	arr[1]=	NULL;
	execve("./minishell", arr, env);
	return (0);
}
