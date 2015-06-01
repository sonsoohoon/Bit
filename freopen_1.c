#include <fcntl.h>
#include <stdio.h>
main()
{
	char *fname = "test.txt";
	FILE *fp;

	printf("First printf is on the screen.\n");
	if((fp = freopen(fname,"w",stdout)) == NULL)
	{
		perror("freopen");
		exit(-1);
	}
	printf("Second printf is in this file\n");
}
