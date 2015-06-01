#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// -rw-r--r-- 1 root root 149 Nov 21 05:23
int main(int argc, char **argv)
{
	struct stat buf;
	struct passwd *pwd;
	struct group *grp;
	char perm[11] = "----------";
	char rwx[] = "rwx";
	int i;
	lstat( argv[1], &buf );

	//printf("%x\n", buf.st_mode );

	if( S_ISDIR( buf.st_mode ) )
		perm[0] = 'd';
	if( S_ISCHR( buf.st_mode ) )
		perm[0] = 'c';
	if( S_ISBLK( buf.st_mode ) )
		perm[0] = 'b';
	if( S_ISSOCK( buf.st_mode ) )
		perm[0] = 's';
	if( S_ISLNK( buf.st_mode ) )
		perm[0] = 'l';
	if( S_ISFIFO( buf.st_mode ) )
		perm[0] = 'p';

	for( i=0; i<9; i++ )
	{
		if( (buf.st_mode >> (8-i)) & 0x1 ) 
			perm[1+i] = rwx[i%3];
	}

	printf("%s", perm );

	printf(" %*d", 3,  buf.st_nlink );

	pwd = getpwuid(buf.st_uid);
	printf(" %s",  pwd->pw_name );

	grp = getgrgid(buf.st_gid);
	printf(" %s",  grp->gr_name );

	if( perm[0] == 'c' || perm[0] == 'b' )
	{
		printf(" %d, %d", (buf.st_rdev>>8)&0xff , buf.st_rdev&0xff);
	}
	else
	{
		printf(" %d", buf.st_size );
	}

	printf(" %s", ctime(&buf.st_mtime));
	if( perm[0] != 'l' )
		printf(" %s\n", argv[1]);
	else
	{
		int ret;
		char temp[100];
		ret = readlink( argv[1], temp, sizeof temp);
		temp[ret] = 0;
		printf(" %s -> %s\n", argv[1], temp);
	}

	return 0;
}









