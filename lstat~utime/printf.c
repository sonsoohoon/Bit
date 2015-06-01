#include <stdio.h>
#include <stdio.h>
void minuprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	double dval;
	int ival;

	vs_start(ap,fmt);

	for(p = fmt;*p;p++)
	{
		if(*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch(*++p)
		{
			case 'd':
				ival = va_arg(ap,int);
				printf("%d",ival);
				break;
			case 'f':
				dval = va_arg(ap,int);
				printf("%d",ival);
				break;
			case 's':
				for(sval = va_arg(ap,char*);*sval;sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
