#include "stdio.h"

int main(int argc, char *argv[])
{
	FILE *fa, *fb;
	fa = fopen("a.txt", "r");
	fb = fopen("b.txt", "w");
	char c;
	while ((c = getc(fa)) != EOF)
		putc(c, fb);
	fflush(fb);

	fclose(fa);
	fclose(fb);

	return 0;
}
