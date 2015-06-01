#if 0
//feof_1.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char *argv[])
{
		FILE *fp;
		int ch;

		if((fp=fopen(argv[1],"w"))==NULL){
				printf("File open error!!\n");
				exit(-1);
		}
		while(!feof(fp)){
				ch = fgetc(fp);
				fputc(ch,stdout);
			if(ferror(fp)){
					printf("Error detected!!\n");
					printf("errno: %d\n",errno);   //EACCESS
					perror("errer: ");
					getchar();
					clearerr(fp);
			}
		}
		fclose(fp);
}
#endif


#if 0
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	char name[L_tmpnam], line[80];
	FILE *fp1;
	FILE *fp2;

	printf("%s\n",tmpnam(NULL));

	tmpnam(name);
	printf("%s\n",name);


	if((fp1 = tmpfile()) == NULL){
			perror("tmpfile error");
			exit(-1);
	}

	if((fp2 = fopen(name,"r")) == NULL){
		perror("tmpfile error");
		exit(-1);
	}
	fputs("one line of output\n",fp1);
	rewind(fp1);
	if(fgets(line,sizeof(line),fp1) == NULL){
			perror("fgets error");
			exit(-1);
	}
	getchar();
	fputs(line,stdout);
	getchar();
	exit(0);
}
#endif

#if 0
#include <stdio.h>
int main()
{
		char buf[BUFSIZ];

		setbuf(stdout,buf);
		printf("Hello, ");sleep(1);
		printf("UNIX!"); sleep(1);
		printf("\n"); sleep(1);

		setbuf(stdout,NULL);
		printf("How ");sleep(1);
		printf("are ");sleep(1);
		printf("you?");sleep(1);
		printf("\n"); sleep(1);

		return 0;
}
#endif

#if 0
//fflush_1.c
#include <stdio.h>
int main()
{
		char *prompt="Prompt>>";
		char command[80];

		for(;;){
				fputs(prompt,stdout);
				if(fgets(command,sizeof(command),stdin)==NULL)
						break;
				system(command);
		}
		fprintf(stdout,"Good Bye...");
//		fflush(stdout);
		system("clear");
}
#endif

#if 0
//vprintf_1.c
#include <stdio.h>
#include <stdarg.h>
int vpf(char *fmt,...)
{
		va_list argptr;
		int cnt;

		va_start(argptr,fmt);
		cnt = vprintf(fmt,argptr);
		va_end(argptr);
		return cnt;
}

int main(void)
{
		int i=30;
		float f=60;
		char *s = "abc";
		int cnt;
		cnt = vpf("%d, %f, %s\n",i,f,s);
		printf("cnt: %d\n",cnt);
}
#endif

#if 0
#include <stdarg.h>
#include <stdio.h>
void miniprintf(char *fmt, ...)
{
		va_list ap;
		char *p, *sval;
		double dval;
		int ival;

		va_start(ap,fmt);

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
							dval = va_arg(ap,double);
							printf("%f",dval);
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
void main()
{
		int n = 20;
		double d = 24.23;
		char msg[] = "hello";
		miniprintf("miniprintf: %d %f %s\n",n,d,msg);
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
		FILE  *fp;
		char buf[1024];
		int num;
		float real;

		if((fp = fopen("test.txt","r")) == NULL)
		{
				perror("fopen error");
				exit(-1);
		}

		while( (fscanf(fp,"%d %f %s",&num,&real,buf)) != EOF)
				printf("%d %f %s\n",num,real,buf);
		fclose(fp);

		return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
		int i;
		struct stat buf;
		char *ptr;

		for(i=1;i<argc;i++){
				printf("%s: ",argv[i]);
				if(stat(argv[i],&buf) < 0){
						perror("lstat()"); continue;
				}
				if(S_ISREG(buf.st_mode)) 		ptr = "regular";
				else if(S_ISDIR(buf.st_mode))	ptr = "directory";
				else if(S_ISCHR(buf.st_mode))	ptr = "character special";
				else if(S_ISBLK(buf.st_mode))	ptr = "block special";
				else if(S_ISFIFO(buf.st_mode))	ptr = "fifo";
				else if(S_ISLNK(buf.st_mode))	ptr = "symbolic link";
				else if(S_ISSOCK(buf.st_mode))	ptr = "socket";
				else							ptr = "** unknown mode **";
				printf("%s\n",ptr);
		}
		printf("%d\n",buf.st_mode>>12);
		exit(0);
}
#endif


#if 0
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char *argv[])
{
		int i;
		struct stat buf;
		struct tm *tmp;
		char *ptr;

		if(stat(argv[1],&buf)<0){
				perror("stat() error");
				exit(-1);
		}
		printf("%ld\n",buf.st_mtime);

		printf(" %s",ctime(&buf.st_mtime));


		tmp = localtime(&buf.st_ctime);
		printf("%04d-%02d-%02d %02d:%02d ", tmp->tm_year+1900, tmp->tm_mon+1, tmp->tm_mday, tmp->tm_hour,tmp->tm_min);

		exit(0);
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
		int i;
		if(argc < 2){
				printf("usage: access_1 file1 file2 ... fileN\n");
				exit(1);
		}

		for(i=1;i<argc;i++){
				if(access(argv[i],F_OK) != 0){
						printf("%s isn't exits.\n",argv[i]);
						continue;
				}
				if(access(argv[i],R_OK) == 0)
						printf("User can read %s\n",argv[i]);
				if(access(argv[i],W_OK)==0)
						printf("User can write %s\n",argv[i]);
				if(access(argv[i],X_OK)==0)
						printf("User can execute %s\n",argv[i]);
		}
}
#endif

#if 0
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
//		umask(002);
		if(open("before.test",O_WRONLY|O_CREAT|O_TRUNC,0777)<0){
				printf("1st open call error\n");
				exit(1);
		}
		umask(077);

		if(open("after.test",O_WRONLY|O_CREAT|O_TRUNC,0777)<0){
				printf("2nd open call error\n");
				exit(2);
		}
}
#endif

#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(void)
{
		struct  stat   statbuf;

		if(stat("before.test",&statbuf)<0){
				perror("stat error for before.test");
				exit(-1);
		}
		if(chmod("before.test",(statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0){
				perror("chmod error for before.test");
				exit(-1);
		}
		/* set absolute mode to "rw-r--r--" */
		if(chmod("after.test", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)<0){
				perror("chmod error for after.test");
				exit(-1);
		}
}
#endif

#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(void)
{
		struct stat   statbuf;
		if(chown("aaa",1003,1004)<0){
				perror("chmod error for aaa");
				exit(-1);
		}
}
#endif

#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(void)
{
		struct stat	statbuf;
		if(truncate("trun.txt",10)<0){
				perror("truncate error");
				exit(-1);
		}
}
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
		int fd;
		if(argc != 3){
				printf("usage: link_1 existfile newfile\n");
				exit(1);
		}

		if(link(argv[1],argv[2])<0){
				printf("link call error\n");
				exit(2);
		}
}
#endif


