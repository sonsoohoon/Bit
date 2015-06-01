#include <stdio.h>
#include <unistd.h>
int main()
{
	char buff[30] = "unbuffed";
	printf("hello ");
	write(1,buff,sizeof(buff));
	sleep(5);
	printf("\n");
}
