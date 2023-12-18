// 2023-12-18
// K&R version doesn't work on Linux
// This is the Linux version of fsize

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>

#define S_IFMT __S_IFMT
#define S_IFDIR __S_IFDIR

void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));

int main(int argc, char *argv[])
{
	if (argc == 1)
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}

void fsize(char *name)
{
	struct stat stbuf;
	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%8s %8s %8s %8s %4s %4s %15s\n", "device", "inode", "mode", "size",
		   "uid", "gid", "name");
	printf("%-8ld %-8ld %-8d %-8ld %-4d %-4d %-15s\n", stbuf.st_dev,
		   stbuf.st_ino, stbuf.st_mode, stbuf.st_size, stbuf.st_uid,
		   stbuf.st_gid, name);
}

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *d;

	if ((d = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}

	while ((dp = readdir(d)) != NULL) {
		if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
			continue;
		if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
		else {
			sprintf(name, "%s/%s", dir, dp->d_name);
			(*fcn)(name);
		}
	}

	closedir(d);
}
