#include <stdio.h>
main()
{
	char *fname = "test.txt";
	long position;
	int ch;
	FILE *fp;

	if((fp=fopen(fname,"r"))==NULL)
	{
		printf("File Open Error\n");
		exit(-1);
	}

	printf("Input number>>");
	scanf("%ld",&position);

	fseek(fp,position-1L,SEEK_SET);
	ch = getc(fp);
	printf("%ldth charactor=> %c\n",position,ch);
	fseek(fp,0L,SEEK_END);
	printf("%d\n",ftell(fp));
	exit(0);
}
CTRLA
