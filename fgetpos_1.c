#include <stdio.h>

int main(void)
{
	FILE *fp;
	fpos_t position;
	int i;

	fp = fopen("sanple.txt","wt");

	for(i=0;i<100;i++)
		putc('A',fp);

	fgetpos(fp,&position);
	printf("posiotion:%ld\n",position);

	rewind(fp);
	printf("%ld",ftell(fp));
	fsetpos(fp,&position);
	position = (fpos_t)0;
	printf("position: %ld\n",position);
	fgetpos(fp,&position);
	printf("position: %ld\n",position);

	fclose(fp);
	return 0;
}
