#include <fcntl.h>
int main(int argc, char** argv){
	if (argc != 2)
		return 0;
	int fd = open(argv[1], O_RDONLY); 
	if (fd == -1)
	{
		printf("fail opening file\n");
		return 1;
	}
	return 0;
}
