#if 0

#include <stdio.h>
#include <signal.h>

void foo(int signo)
{
	printf("foo: signo : %d\n",signo);
}
int main()
{
	void (*p)(int);
	p = signal(SIGINT,foo);
	printf("%p\n",p);
	p(3);
	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <signal.h>

int main()
{
	int i;
	signal(SIGINT,SIG_IGN);
	for(i=0;i<5;i++)
	{
		printf("...sig: SIG_IGN\n");
		sleep(1);
	}
}
#endif

#if 0
#include <sys/types.h>
#include <signal.h>
int main()
{
	while(1)
	{
		sleep(1);
		printf(".\n");
	}
}
#endif


