#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <errno.h>

#define S_IFMT __S_IFMT
#define S_IFDIR __S_IFDIR

int main(int argc, char *argv[])
{
	char *dirname = ".";
	DIR *dir;
	struct dirent *dp;
	// int fd = open(dirname, O_RDONLY, 0);
	dir = opendir(dirname);
	// printf("fd: %d\n", fd);

	// struct direct dirbuf;
	// printf("sizeof(dirbuf): %ld\n", sizeof(dirbuf));
	// ssize_t r = read(fd, (char *)&dirbuf, sizeof(dirbuf));
	dp = readdir(dir);

	// if (r < 0) {
	// 	int errnum = errno;
	// 	printf("read failed: (%d: %s)\n", errnum, strerror(errnum));
	// }
	printf("dp->name: %s\n", dp->d_name);

	// close(dir->fd);
	closedir(dir);
	return 0;
}
