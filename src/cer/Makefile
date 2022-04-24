CFLAGS = -Werror -Wall -Wextra


Lib:
	$(MAKE) -C ../../Libft


all:

cd: Lib
	gcc cd.c ../../Libft/libft.a utils.c -o cd_test

pwd:
	gcc pwd.c -o pwd_test

ms:
	gcc ms_command_loops_test.c ms_command_exec.c ms_command_opening_fds.c ms_find_executable_path.c open_access_files.c utils.c libft.a -lreadline