#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	int ret;
	int test;
	char buff[1];

	mkfifo("myfifo",0666);


	fd = open("myfifo",O_RDWR);
    if(fd == -1)
	{
	perror("open() 실행에러");
	exit(1);
	}
	while(1)
	{
		read(fd,buff,1);
		printf("%c\n",buff[0]);
	}
	return 0;
}
