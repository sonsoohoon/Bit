#include <stdio.h>

struct student
{
	int sno;
	char name[10];
	int point;
};
main()
{
	struct student s1,s2;
	FILE *fp;
	if((fp = fopen("student.dat","w"))==NULL)
	{
		perror("fopen error");
		exit(-1);
	}
	printf("input SNO >>");
	scanf("%d",&s1.sno);
	printf("input name>>");
	scanf("%s",&s1.name);
	printf("input Point>>");
	scanf("%d",&s1.point);
