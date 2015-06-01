#include <stdio.h>

main(int argc, char ** argv)
{
	in nbyte;
	char buf[50];

	if(argc != 2){
		printf("usage : readlink_1 symlinkname\n");
		exit(1);
	}
	if((nbyte = readlink(argv[1], buf, 50))<0){
		printf("readlink call error\n");
		exit(2);
	}
	else
	{
		buf[nbyte] = '\0';
		printf("buf : %s \n", buf);
	}
}

