#include <stdio.h>
#include <stdlib.h>
extern char **environ;
char glob_var[]="HOBBY=swimming";
void addone()
{
	char auto_var[10];
	strcpy(auto_var,"LOVER=wr");
	putenv(auto_var);
}
int main()
{
	int i;
	for(i=0;environ[i] !=NULL;i++)
		printf("environ[%d]: %s\n",i,environ[i]);

	putenv(glob_var)
		addone();
	printf("My hobby is %s\n",getenv("HOBBY"));
	printf(":
