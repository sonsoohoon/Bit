#include <sys/types.h>
#include <sys/stat.h>

main()
{
	struct stat statbuf;

	if(lchown("aaa",0,0)<0){
		perror("chmod error for aaa");
		exit(-1);
	}
}
