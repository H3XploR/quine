#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	int	index = 5;
	char	filename[8];
	char	filename_source[10];
	char*	base_name_file = "Sully_";
	char	exec_filename[50];
	snprintf(filename, 100, "%s%d", base_name_file, index);
	snprintf(filename_source, 100, "%s.c", filename);
	snprintf(exec_filename, 100, "cc %s -o %s", filename_source, filename);
	if (index >= 0){
		int fd = open(filename_source, O_CREAT, O_RDWR | S_IRWXU); 
		int ret_exec = execl(exec_filename, exec_filename, NULL);
		//Compiler Sully_X.c ---> Sully_X
		//Lancer le Sully_X.c
		close(fd);
	}
	return 0;
}
