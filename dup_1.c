#include <fcntl.h>
#include <string.h>
#include <unistd.h>
main()
{
	char *fname = "test.txt";
	int fd1,fd2,cnt;
	char buf[30];

	fd1 = open(fname,O_RDONLY);
	printf("%d\n",fd1);
	if(fd1 < 0)
	{
		perror("open()");
		exit(-1);
	}
	fd2 = dup(fd1);
	printf("%d\n",fd2);
	cnt = read(fd1,buf,12);
	buf[cnt] = '\0';
	printf("fd1's printf : %s\n",buf);
	lseek(fd1,1,SEEK_CUR);
	cnt =read(fd2,buf,12);
	buf[cnt] = '\0';
	printf("fd2's printf :%s\n",buf);
}
