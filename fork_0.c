#include <stdio.h>

main()
{
	printf("pid = %d,ppid = %d\n",getpid(),getppid());

	fork();

	printf("pid = %d,ppid = %d\n",getpid(),getppid());
}

