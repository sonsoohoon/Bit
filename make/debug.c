#include<stdio.h>

int main()
{
printf("***main***\n");
#ifdef DEBUG
printf("***debug***\n")
#endif
return 0;
}
