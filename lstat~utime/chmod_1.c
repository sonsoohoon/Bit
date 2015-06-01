#include <sys/types.h>
#include <sys/stat.h>

main()
{
	struct stat  statbuf;
	/* turn on set-ground-ID and turn off group-execute */

	if(stat("befor.test", &statbuf)<0){
		perror("stat error for befoere.test");
		exit(-1);
	}
	if(chmod("before.test",(statbuf.st_mode & ~S_IXGRP)|S_ISGID)<0){
		perror("chmod error for before.test");
		exit(-1);
	}
	/* set absolute mode to "rw-r--r--" */
	if(chmod("after.test",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)<0){
		perror("chmod error for after.test");
		exit(-1);
	}
}

