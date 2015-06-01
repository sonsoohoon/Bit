#include <fcntl.h>

//# mkfifo myfifo
int main()
{
	int fd;
	int ret;
	char buff[100];
	mkfifo("myfifo",O_RDWR);

	fd = open("myfifo", O_WRONLY);
	while(1)
	{
	buff[0]=getchar();
	write(fd,buff,1);
	}
	write(fd,"\n",1);
	close(fd);
	return 0;
}
