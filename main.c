#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = 0;
	fd = open("./test.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("%s\n", "file open error");
		exit(0);
	}
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
