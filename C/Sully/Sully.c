#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int	index = 5;
	char	filename[8];
	char	filename_source[10];
	const char*	base_name_file = "Sully_";
	char	exec_filename[50];
	snprintf(filename, 100, "%s%d", base_name_file, index);
	snprintf(filename_source, 100, "%s.c", filename);
	snprintf(exec_filename, 100, "cc %s -o %s", filename_source, filename);
	if (index >= 0){
		int fd = open(filename_source, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU); 
		const char*	source_code = "#include <stdio.h>%c#include <fcntl.h>%c#include<unistd.h>%c%cint main(void){%c\tint\tindex = 5;%c\tchar\tfilename[8];%c\tchar\tfilename_source[10];%c\tconst char*\tbase_name_file = %cSully_%c;%c\tchar\texec_filename[50];%c\tsnprintf(filename, 100, %c%%s%%d%c, base_name_file, index);\n";
		dprintf(fd, source_code, 10, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 34 , 34);
		int ret_system = system(exec_filename);
		close(fd);
	}
	return 0;
}
