#include "../../includes/minishell.h"

int	open_with_no_append_nocreate(char *path, int access_flag)
{
	int	fd;

	if (access_flag == READS_ONLY)
		fd = open(path, O_RDONLY | O_TRUNC, 0777);
	else if (access_flag == WRITES_ONLY)
		fd = open(path, O_WRONLY| O_TRUNC, 0777);
	else if (access_flag == READS_AND_WRITES)
		fd = open(path, O_RDWR | O_TRUNC, 0777);
	return (fd);
}

int	open_with_append_create(char *path, int access_flag)
{
	int	fd;

	if (access_flag == READS_ONLY)
		fd = open(path, O_CREAT | O_RDONLY | O_APPEND, 0777);
	else if (access_flag == WRITES_ONLY)
		fd = open(path, O_CREAT | O_WRONLY| O_APPEND, 0777);
	else if (access_flag == READS_AND_WRITES)
		fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0777);
	return (fd);
}

int	open_with_no_append_create(char *path, int access_flag)
{
	int	fd;

	if (access_flag == READS_ONLY)
		fd = open(path, O_CREAT | O_RDONLY | O_TRUNC, 0777);
	else if (access_flag == WRITES_ONLY)
		fd = open(path, O_CREAT | O_WRONLY| O_TRUNC, 0777);
	else if (access_flag == READS_AND_WRITES)
		fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0777);
	return (fd);
}
int	open_with_append_nocreate(char *path, int access_flag)
{
	int	fd;

	if (access_flag == READS_ONLY)
		fd = open(path, O_RDONLY | O_APPEND, 0777);
	else if (access_flag == WRITES_ONLY)
		fd = open(path, O_WRONLY | O_APPEND, 0777);
	else if (access_flag == READS_AND_WRITES)
		fd = open(path, O_RDWR | O_APPEND, 0777);
	return (fd);
}

int	open_and_check_access(char *path, int access_flag, bool append, bool create)
{
	int	fd;
	if (access(path, F_OK))
		return (-1);
	if (access(path, access_flag))
		return (-2);
	if (append == true && create == true)
		fd = open_with_append_create(path, access_flag);
	else if (append == true && create == false)
		fd = open_with_append_nocreate(path, access_flag);
	else if (append == false && create == true)
		fd = open_with_no_append_create(path, access_flag);
	else if (append == false && create == false)
		fd = open_with_no_append_nocreate(path, access_flag);
	return (fd);
}