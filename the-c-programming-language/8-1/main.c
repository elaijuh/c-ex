#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

void errorf(char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

void filecopy(int f1, int f2)
{
	int n;
	char buf[BUFSIZ];
	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(f2, buf, n) != n)
			errorf("cat: write error to stdout");
}

int main(int argc, char *argv[])
{
	int fd;
	if (argc == 1) // cat from stdin
		filecopy(0, 1);
	else
		while (--argc > 0) {
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
				errorf("cat: can't open %s", *argv);
			filecopy(fd, 1);
		}

	return 0;
}
