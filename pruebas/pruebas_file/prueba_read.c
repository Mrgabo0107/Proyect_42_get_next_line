#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	char buff[6];
	int	fd;
	int	fd2;
	int	ret;

	fd = open("test_file.txt", O_RDONLY);
	fd2 = open("test_file2.txt", O_RDONLY);
	printf("fd: %d\n",fd);
	printf("fd2: %d\n",fd2);
	printf("---------------------------\n");
//	ret = read(fd, buff, 3);
//	printf("ret = %d, buff = %s\n", ret, buff);
	ret = read(fd2, 0, 0);
	printf("ret = %d, buff = %s\n", ret, buff);
//	ret = read(fd, buff, 3);
//	printf("ret = %d, buff = %s\n", ret, buff);
//	ret = read(fd2, buff, 3);
//	printf("ret = %d, buff = %s\n", ret, buff);
	close(fd);
	close(fd2);
	return (0);
}
