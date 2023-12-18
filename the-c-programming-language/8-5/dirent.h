#include <sys/types.h>

#define S_IFMT __S_IFMT
#define S_IFDIR __S_IFDIR

#define NAME_MAX 14

typedef struct {
	long ino;
	char name[NAME_MAX + 1];
} Dirent;

typedef struct {
	int fd;
	Dirent d;
} DIR;

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct {
	ino_t d_ino;
	off_t d_off;
	unsigned short int d_reclen;
	unsigned char d_type;
	char d_name[DIRSIZ];
};

extern DIR *opendir(char *);
extern Dirent *readdir(DIR *);
extern void closedir(DIR *);
