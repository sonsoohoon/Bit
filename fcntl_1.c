#include <fcntl.h>
main()
{
	char *fname = "test.txt";
	int fd,newfd;
	int flag;

	if((fd = open(fname,O_RDWR | O_APPEND)) < 0)
	{
		perror("open()");
		exit(-1);
	}

	flag = fcntl(fd,F_GETFL,0);
	if(flag & O_APPEND)
		printf("fd : O_APPEND flag is set.\n");
	else
		printf("fd:O_APPEND flag is NOT set.\n");
}
