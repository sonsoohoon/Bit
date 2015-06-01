#include <stdio.h>

main(int argc, char ** argv)
{
	int fd;
	if(argc != 3){
		printf("usage : remove_1 oldname newname \n");
		exit(1);
	}
	if(link(argv[1], argv[2])<0){
		printf("link call error\n");
		exit(2);
	}
	else printf("step1 passed\n");

	if(remove(argv[1])<0){
		printf("unlink error\n");
		exit(3);
	}
	else printf("step2 passed\n");

	printf("success\n");
}

