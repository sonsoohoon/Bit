#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	pid_t pid;
	sleep(3);
	printf("\nProec ID      =  %d\n",pid=getpid());
	printf("Parent Process ID = %d\n",getppid());
	printf("Real User id = %d\n",getuid());
	printf("Effective User ID = %d\n",geteuid());
	printf("Real group ID = %d\n",getpid());
	printf("Effective group ID = %d\n",getegid());
}
