#include <fcntl.h>
#include <string.h>
#include <unistd.h>

main()
{
	char *fname = "test.txt";
	int fd1;//첫번째 오픈
	int fd2;//두번째 오픈
	int cnt;//읽은 바이트수
	char buf[30];

	fd1 = open(fname,O_RDONLY);
	fd2 = open(fname,O_RDONLY);
	if(fd1 < 0 || fd2 < 0)
	{
		perror("open()");
		exit(-1);
	}
	cnt = read(fd1,buf,12);
	buf[cnt] = '\0';
	printf("fd1's first printf: %s\n",buf);
	lseek(fd1,1,SEEK_CUR);
	cnt = read(fd1,buf,12);
	buf[cnt] = '\0';
	printf("fd1;s second printf: %s\n",buf);
	cnt = read(fd2,buf,12);
	buf[cnt] = '\0';
	printf("fd2's first printf: %s\n",buf);
	lseek(fd2,1,SEEK_CUR);
	cnt = read(fd2,buf,12);
	buf[cnt] = '\0';
	printf("fd2;s second printf: %s\n",buf);
	exit(0);
}
