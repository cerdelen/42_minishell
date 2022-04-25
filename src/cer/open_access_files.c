#include "../../includes/minishell.h"

int	open_with_no_append_nocreate(char *path, int access_flag)
{
	int	fd;

	printf("%s\n", path);
	printf("%d == %d\n", access_flag, READS_ONLY);
	if (access_flag == READS_ONLY)
	{
		printf("HELLO HELLO HELLO \n");
		printf("fd == %d\n", fd);
		fd = open(path, O_RDONLY);
		printf("fd == %d\n", fd);
	}
	if (access_flag == WRITES_ONLY)
		fd = open(path, O_WRONLY | O_TRUNC, 0644);
	if (access_flag == READS_AND_WRITES)
		fd = open(path, O_RDWR | O_TRUNC, 0644);
	printf("fd == %d\n", fd);
	return (fd);
}

int	open_with_append_create(char *path, int access_flag)
{
	int	fd;

	if (access_flag == READS_ONLY)
		fd = open(path, O_CREAT | O_RDONLY | O_APPEND, 0644);
	else if (access_flag == WRITES_ONLY)
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	return (fd);
}

int	open_with_no_append_create(char *path, int access_flag)
{
	int	fd;

	if (access_flag == READS_ONLY)
		fd = open(path, O_CREAT | O_RDONLY | O_TRUNC, 0644);
	else if (access_flag == WRITES_ONLY)
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	open_with_append_nocreate(char *path, int access_flag)
{
	int	fd;

	if (access_flag == READS_ONLY)
		fd = open(path, O_RDONLY | O_APPEND, 0644);
	else if (access_flag == WRITES_ONLY)
		fd = open(path, O_WRONLY | O_APPEND, 0644);
	else
		fd = open(path, O_RDWR | O_APPEND, 0644);
	return (fd);
}

int	open_and_check_access(char *path, int access_flag, bool append, bool create)
{
	int	fd;
	int	check;

	check = 0;
	if (create == false)
		if (access(path, F_OK) != 0)
			return (print_error_message(path, NULL));
	printf("HIELLO\n");
	if (access_flag != READS_ONLY)
		check = access(path, W_OK);
	if (check != 0)
		return (print_error_message(path, NULL));
	if (access_flag != WRITES_ONLY)
		check = access(path, R_OK);
	if (check != 0)
		return (print_error_message(path, NULL));
	if (append == true && create == true)
		fd = open_with_append_create(path, access_flag);
	else if (append == true && create == false)
		fd = open_with_append_nocreate(path, access_flag);
	else if (append == false && create == true)
		fd = open_with_no_append_create(path, access_flag);
	else
	{
		printf("hello2\n");
		fd = open_with_no_append_nocreate(path, access_flag);
	}
	return (fd);
}
