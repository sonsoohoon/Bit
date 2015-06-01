#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd, len;
	int fd1;
	char buf[20];
	
	if((fd=open("tempfile",O_RDWR|O_CREAT|O_TRUNC,0666))<0){
		perror("open error");
		exit(-1);
	}

	unlink("tempfile");

	if(write(fd, "How are you?",12)!=12){
		perror("write error");
		exit(-1);
	}
	lseek(fd, 0L, SEEK_SET);
	if((len = read(fd, buf, sizeof(buf)))<=0)
	{
		perror("read error");
		exit(-1);
	}
	else buf[len] = '\0';
	printf("%s\n",buf);
//	close(fd);

	if((fd1=open("tempfile", O_RDWR))<0){
		perror("Second open error");
//		exit(-1);
	}

	
		write(fd,"hello world",11);
		lseek(fd,-11,SEEK_CUR);
		len = read(fd,buf,sizeof(buf));
		buf[len] = '\0';
		printf("%s\n",buf);
		exit(0);
	
//		close(fd);
	exit(0);
}

