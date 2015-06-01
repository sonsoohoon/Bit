#include <sys/types.h>
#include <sys/stat.h>

main(void)
{
	struct stat statbuf;

	if(truncate("trun.txt",10)<0){
		perror("truncate error");
		exit(-1);
	}
}
