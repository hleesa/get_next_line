#include "get_next_line.h"
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char* line;
	int	check;
	int	fd;

	printf
	fd = open("test.txt", O_RDONLY);
	while ((check = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}


 *seonjeon/
 *
 */


#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 10

void check()
{
	static int i;

	++i;
	printf("%d\n", i);

}

int main()
{

	int fd = 0;
//	int ret;
//	char buff[BUFFER_SIZE] = {0,};
	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
		printf("%s\n", "file open error");
	get_next_line(fd);
	get_next_line(fd);
//	ret = read(fd, buff, BUFFER_SIZE);
//	printf("ret: %d\n",ret);
//	printf("buff: %s\n", buff);
//	printf("--------------------\n");
//
//	ret = read(fd, buff, BUFFER_SIZE);
//	printf("ret: %d\n",ret);
//	printf("buff: %s\n", buff);
//	printf("--------------------\n");
//
//	ret =read(fd, buff, BUFFER_SIZE);
//	printf("ret: %d\n",ret);
//	printf("buff: %s\n\n", buff);
//	printf("--------------------\n");
//
//	ret = read(fd, buff, BUFFER_SIZE);
//	printf("ret: %d\n",ret);
//	printf("buff: %s\n\n", buff);
//	printf("--------------------\n");
//
//	check();
//	check();
//	check();
//	check();
}
